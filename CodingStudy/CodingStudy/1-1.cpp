// BAEKJOON 2580
// Sudoku
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

stack<vector<int>> arr;
queue<vector<int>> board_arr;
queue<pair<int, int>>zero_arr;

void showBoard(vector<int>& board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", board[i * 9 + j]);
		}
		printf("\n");
	}
}

bool isPerfect(vector<int>& board) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (board[i * 9 + j] == 0)
				return false;
	return true;
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

void BFS(vector<int>& board, bool* check) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i * 9 + j] == 0) {
				for (int k = 0; k < 9; k++) {
					if (!check[board[i * 9 + k]]) {
						check[board[i * 9 + k]] = true;
					}
					
					if (!check[board[k * 9 + j]]) {
						check[board[k * 9 + j]] = true;
					}
				}

				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (!check[board[ ((i / 3) * 3 + a) * 9 + ((j / 3) * 3 + b)]]) {
							check[board[((i / 3) * 3 + a) * 9 + ((j / 3) * 3 + b)]] = true;
						}
					}			
				}

				for (int k = 1; k < 10; k++)
					if (!check[k]) {
						board[i * 9 + j] = k;
						board_arr.push(board);
					}


			}
		
		}
		
	}
}
void makeGuess() {
	vector<int> board;
	bool check[10] = { false };
	while (!board_arr.empty()) {
		board = board_arr.front();
		board_arr.pop();
		//showBoard(board);
	//	cout << endl;
		make_false(check);
		if (isPerfect(board)) {
			break;
		}
		else
			BFS(board, check);

	}
	showBoard(board);

}

bool finished = false;
vector<int> answer_board;
int cnt = 0;
int cnt2 = 1;
int cnt3 = 1;
void DFS(vector<int> board) {
	if (isPerfect(board)) {
		answer_board = board;
	}
	else {
		bool check[10] = { false };
		//cout << cnt3 << "======" << endl;
		//showBoard(board);
		//finished = true;

		//vector<int> board;
		//board = arr.top();
		//arr.pop();
		cnt = 0;
		make_false(check);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i * 9 + j] == 0) {
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
						
						for (int b = 0; b < 3; b++) {
							if (!check[board[((i / 3) * 3 + a) * 9 + ((j / 3) * 3 + b)]]) {
								check[board[((i / 3) * 3 + a) * 9 + ((j / 3) * 3 + b)]] = true;
							}

						}
					}
					/*
					for (int k = 1; k < 10; k++)
						if (!check[k]) {
							board[i * 9 + j] = k;
							arr.push(board);
						}

						*/

					for (int k = 1; k < 10; k++) {
						if (!check[k]) {
							board[i * 9 + j] = k;
							if (isPerfect(board)) {
								answer_board = board;
								//cout << cnt2<<"======" << endl;
								//showBoard(board);
								finished = true;
						
								//cnt2++;
							}
							if (!finished)
								DFS(board);
						}
					}
					break;
				}
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

	//board_arr.push(board);
	//arr.push(board);
	//bool check[10] = { false };
	
	//while (!isPerfect(arr.top()))
		
	DFS(board);
	showBoard(answer_board);
	//showBoard(arr.top());
//	makeGuess();

	/*
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

	show_board(board);*/
	return 0;
}