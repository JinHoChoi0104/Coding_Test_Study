#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largest_num = 0, N, m[2][4] = { {-1,1,0,0}, {0,0,-1,1} }; //up, down, left, right

int findBig(vector<vector<int>> board) {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			largest_num = max(largest_num, board[i][j]);
	return 0;
}

void adding(vector<vector<int>>& board, int i, int j, int dir) {
	int tox = i - m[0][dir], toy = j - m[1][dir];
	while (tox > -1 && tox < N && toy > -1 && toy < N) {
		if (board[tox][toy] == 0) 
			tox -= m[0][dir], toy -= m[1][dir];
		else if (board[tox][toy] == board[i][j]) {
			board[i][j] *= 2;
			board[tox][toy] = 0;
			i = tox, j = toy;
			return;
		}
		else {
			i = tox + m[0][dir], j = toy + m[1][dir];
			return;
		}
	}
}
void moving(vector<vector<int>>& board, int fromx, int fromy, int dir) {
	int tox = fromx + m[0][dir], toy = fromy + m[1][dir];
	while (tox > -1 && tox < N && toy > -1 && toy < N) {
		if (board[tox][toy] == 0) {
			board[tox][toy] = board[fromx][fromy];
			board[fromx][fromy] = 0;
			fromx = tox, fromy = toy;
			tox += m[0][dir], toy += m[1][dir];
		}
		else
			return;
	}
}
void DFS(vector<vector<int>> board, int cnt, int dir) {
	if (dir == 0) { //up
		for (int j = 0; j < N; j++) {//y 
			for (int i = 0; i < N; i++) //x
				if (board[i][j] != 0)
					adding(board, i, j, dir);
			for (int i = 0; i < N; i++)
				if (board[i][j] != 0)
					moving(board, i, j, dir);
		}
	}
	else if (dir == 1){ //down
		for (int j = 0; j < N; j++) { //y 
			for (int i = N - 1; i >= 0; i--) //x
				if (board[i][j] != 0)
					adding(board, i, j, dir);
			for (int i = N - 1; i >= 0; i--)
				if (board[i][j] != 0)
					moving(board, i, j, dir);
		}
	}
	else if (dir == 2) {//left
		for (int i = 0; i < N; i++) {//x
			for (int j = 0; j < N; j++)  //y
				if (board[i][j] != 0) 
					adding(board, i, j, dir);	
			for (int j = 0; j < N; j++) 
				if (board[i][j] != 0) 
					moving(board, i, j, dir);
		}
	}
	else if (dir == 3) { //right
		for (int i = 0; i < N; i++) { //x
			for (int j = N - 1; j >= 0; j--)  //y 
				if (board[i][j] != 0)
					adding(board, i, j, dir);
			for (int j = N - 1; j >= 0; j--)
				if (board[i][j] != 0)
					moving(board, i, j, dir);
		}
	}
	if (cnt != 5)
		for (int k = 0; k < 4; k++)
			DFS(board, cnt + 1, k);
	else
		findBig(board);
	
}

int main() {
	vector<vector<int>>  board(20, vector<int>(20));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	for (int k = 0; k < 4; k++)
		DFS(board, 1, k);

	printf("%d", largest_num);

	return 0;
}