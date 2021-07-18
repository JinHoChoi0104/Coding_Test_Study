#include<iostream>
#include<algorithm>
using namespace std;

int n, max_locate = 0;//board size
int p, q;
bool canLocate(bool board[][10]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j])
				return true;
	return false;
}

int m0[4] = { 1, 1, -1, -1 }, m1[4] = { 1,-1 ,-1,1 };
void locateBishop(int x, int y, bool arr[][10], int cnt) {
	bool board[10][10];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = arr[i][j];

	board[x][y] = false;
	for (int i = 0; i < 4; i++) { //lock diagonal
		p = x + m0[i], q = y + m1[i];
		while (p > -1 && p < n && q > -1 && q < n) {
			board[p][q] = false;
			p += m0[i], q += m1[i];
		}
	}

	if (!canLocate(board)) // if cant locate any more
		max_locate = max(max_locate, cnt + 1);
	else { // can locate more bishop
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j]) {
					p = i, q = j;
					while (p < n && q > -1) {
						if (board[p][q])
							locateBishop(p, q, board, cnt+1);
						p++, q--;
					}
					i = n, j = n;
				}
	}
}

int main(void) {
	bool board[10][10]; //true: can go , false: can't go
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x)
				board[i][j] = true;
			else
				board[i][j] = false;
		}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j]) {
				p = i, q = j;
				while (p < n &&q > -1) {
					if (board[p][q]) 
						locateBishop(p, q, board, 0);
					p++, q--;
				}
				i = n, j = n;
			}

	cout << max_locate;
}