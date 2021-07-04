// BAEKJOON 9663
#include<iostream>
using namespace std;

void locateQueen(int y, int x, int N, bool isAble[][14]) {
	for (int i = 0; i < N; i++) 
		isAble[y][i] = false;
	for (int i = 0; i < N; i++)
		isAble[i][x] = false;

	int y2 = y, x2 = x;
	while (y2 >= 0 && x2 >= 0) 
		isAble[y2--][x2--] = false;

	y2 = y, x2 = x;
	while (y2 >= 0 && x2 < N) 
		isAble[y2--][x2++] = false;

	y2 = y, x2 = x;
	while (y2 < N && x2 >= 0) 
		isAble[y2++][x2--] = false;

	y2 = y, x2 = x;
	while (y2 < N && x2 < N) 
		isAble[y2++][x2++] = false;
}

void chessTree(int y, int x, int N, bool isAble[][14], int *cnt) { // (0~N-1, 0)
	bool isAble2[14][14];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			isAble2[i][j] = isAble[i][j];
	locateQueen(y, x, N, isAble2);

	for (int i = 0; i < N; i++) {
		if (isAble2[i][x + 1]) {
			if (x + 1 == N - 1)
				(*cnt)++;
			else
				chessTree(i, x + 1, N, isAble2, cnt);
		}
	}
}

void showMeTheBoard(int N, bool board[][14]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j])
				printf("0");
			else
				printf("1");
		}
		printf("\n");
	}
}

int main(void) {
	int N;
	cin >> N;
 
	bool isAble[14][14];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			isAble[i][j] = true;

	int cnt = 0, cnt2 = 0;
	if (N != 1) {
		for (int i = 0; i < N; i++) {
			cnt2 = 0;
			chessTree(i, 0, N, isAble, &cnt2);
			cnt += cnt2;
		}
	}
	cout << cnt << endl;

	return 0;
}