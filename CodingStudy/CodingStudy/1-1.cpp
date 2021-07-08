// BAEKJOON 2580
// Sudoku
#include<iostream>
#include<queue>
#include<vector>

using namespace std;


void showBoard(vector<int>& board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", board[i * 9 + j]);
		}
		printf("\n");
	}
}

void findZero(vector<int> board, queue<pair<int, int>>& arr) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (board[i * 9 + j] == 0)
				arr.push(make_pair(i, j));
}

void make_false(bool* check) {
	for (int i = 0; i < 10; i++)
		check[i] = false;
}

bool finished = false;
vector<int> answer_board;

void DFS(vector<int> board, queue<pair<int, int>> zero_arr) {
	if (zero_arr.empty()) {
		answer_board = board;
		finished = true;
	}
	else {
		bool check[10] = { false };
		int cnt = 0;
		make_false(check);

		int i = zero_arr.front().first;
		int j = zero_arr.front().second;
		zero_arr.pop();


		for (int k = 0; k < 9; k++) {
			if (!check[board[i * 9 + k]]) {
				check[board[i * 9 + k]] = true;
				cnt++;
			}

			if (!check[board[k * 9 + j]]) {
				check[board[k * 9 + j]] = true;
				cnt++;
			}
			if (cnt == 10)
				break;
		}

		for (int a = 0; a < 3; a++) {
			if (cnt == 10)
				break;
			for (int b = 0; b < 3; b++) {
				if (!check[board[((i / 3) * 3 + a) * 9 + ((j / 3) * 3 + b)]]) {
					check[board[((i / 3) * 3 + a) * 9 + ((j / 3) * 3 + b)]] = true;
				}
			}
		}

		for (int k = 1; k < 10; k++) {
			if (!check[k]) {
				board[i * 9 + j] = k;
				if (!finished)
					DFS(board, zero_arr);
				else
					break;
			}
		}
	}
}
int main(void) {
	vector<int> board;
	int num = 0;
	for (int i = 0; i < 81; i++) {
		scanf("%d", &num);
		board.push_back(num);
	}
	
	queue<pair<int, int>> zero_arr;
	findZero(board, zero_arr);

	DFS(board, zero_arr);

	showBoard(answer_board);
	return 0;
}