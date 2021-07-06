// BAEKJOON 2580
// Sudoku
#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, int>>zero_arr;

void show_board(int board[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

void findZero(int board[][9]) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (board[i][j] == 0)
				zero_arr.push(make_pair(i, j));
}

void showZero() {
	while (!zero_arr.empty()) {
		cout << zero_arr.front().first << ", " << zero_arr.front().second << endl;
		zero_arr.pop();
	}
}

void make_false(bool* check) {
	for (int i = 0; i < 10; i++)
		check[i] = false;
}

bool makeZeroToNum(int board[][9], int i, int j, bool* check) {
	int cnt = 0;

	for (int k = 0; k < 9; k++) {
		if (!check[board[i][k]]) {
			check[board[i][k]] = true;
			cnt++;
		}
		if (!check[board[k][j]]) {
			check[board[k][j]] = true;
			cnt++;
		}
		if (cnt == 9)
			break;
	}

	//box
	if (cnt != 9) {
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (!check[board[(i / 3) * 3 + a][(j / 3) * 3 + b]]) {
					check[board[(i / 3) * 3 + a][(j / 3) * 3 + b]] = true;
					cnt++;
				}
				if (cnt == 9)
					break;
			}
			if (cnt == 9)
				break;
		}
	}

	if (cnt == 9) {
		for (int k = 1; k < 10; k++)
			if (!check[k]) {
				board[i][j] = k;
				return true;
			}
	}

	return false;
}

int main(void) {
	int board[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &board[i][j]);

	findZero(board);

	int y = 0, x = 0;
	bool check[10] = { false };
	while (!zero_arr.empty()) {
		y = zero_arr.front().first;
		x = zero_arr.front().second;
		zero_arr.pop();

		if(!makeZeroToNum(board, y, x, check))
			zero_arr.push(make_pair(y, x));
		make_false(check);
	}

	show_board(board);
	return 0;
}