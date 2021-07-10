// BAEKJOON 1941
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int arr[5][5];
void showRoutine(vector<pair<int, int>>routine) {
	cout << "========" << endl;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] = 0;
	int y = 0, x = 0;
	while (!routine.empty()) {
		y = routine.back().first;
		x = routine.back().second;
		arr[y][x] = 1;
		routine.pop_back();
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}
void DFS(int y, int x, vector<pair<int, int>> routine, int n) {
	if (y > -1 && y < 5 && x > -1 && x < 5) {
		//cout << "a";
		routine.push_back(pair<int, int>(y, x));
		n++;
		if (n == 4)
			showRoutine(routine);
		else {
			DFS(y + 1, x, routine, n);
			DFS(y, x + 1, routine, n);
			DFS(y - 1, x, routine, n);
			DFS(y, x - 1, routine, n);
		}
	}
	
}



int main(void) {
	vector<pair<int, int>> routine;
	//DFS(2, 2, routine, 0);
	routine.push_back(pair<int, int>(1, 1));
	routine.push_back(pair<int, int>(1, 2));


	vector<pair<int, int>> routine2;
	//DFS(2, 2, routine, 0);
	routine2.push_back(pair<int, int>(1, 1));
	routine2.push_back(pair<int, int>(1, 2));

	vector<vector<pair<int, int>>>arr;
	arr.push_back(routine);
	arr.push_back(routine2);

	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	vector<pair<int, int>> a;
	while (!arr.empty()) {
		a = arr.back();
		arr.pop_back();
		cout << "=====" << endl;

		while (!a.empty()) {
			cout << a.back().first << ", " << a.back().second << endl;
			a.pop_back();
		}
	}
}