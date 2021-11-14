#include <iostream>
#include <vector>
using namespace std;

void showArr(vector<vector<int>>& arr);
void makeNum(vector<vector<int>>& arr, int x, int y);
void makeSudoku(vector<vector<int>> arr, int x, int y, int num);
bool is_done = false;

void showArr(vector<vector<int>>& arr) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}

void makeNum(vector<vector<int>> &arr, int x, int y) {
	vector<bool> check(10, false);

	//check row
	for (int i = 0; i < 9; i++)
		check[arr[x][i]] = true;
	//check col
	for (int i = 0; i < 9; i++)
		check[arr[i][y]] = true;
	//check box
	int p = x/3, q = y/3;
	p *= 3, q *= 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			check[arr[p + i][q + j]] = true;

	//type sudoku
	for(int i=1; i<=9; i++)
		if (!check[i] && !is_done) {
			makeSudoku(arr, x, y, i);
		}
}

void makeSudoku(vector<vector<int>> arr, int x, int y, int num) {
	arr[x][y] = num;
	for(int i=x; i< 9; i++)
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {
				makeNum(arr, i, j);
				return;
			}
		}

	is_done = true;
	showArr(arr);
}

int main() {
	vector<vector<int>> arr(9,vector<int>(9));
	
	int x=-1, y=-1;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 0 && x == -1)
				x = i, y = j;
		}

	if (x == -1) {
		showArr(arr);
		return 0;
	}

	makeNum(arr, x, y);
	return 0;
}