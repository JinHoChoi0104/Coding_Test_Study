#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp(500, vector<int>(500, -1));
vector<vector<int>> arr(500, vector<int>(500));
int N, M;
int getPath(int x, int y) {
	//if (x == -1 || y == -1) return 0;
	
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	
	ret = 0;
	if (x > 0) {
		if (arr[x - 1][y] > arr[x][y])
			ret += getPath(x - 1, y);
	}
	if (y > 0) {
		if (arr[x][y - 1] > arr[x][y])
			ret += getPath(x, y - 1);
	}
	if (x < N - 1) {
		if (arr[x + 1][y] > arr[x][y])
			ret += getPath(x + 1, y);
	}
	if (y < M - 1) {
		if (arr[x][y + 1] > arr[x][y])
			ret += getPath(x, y + 1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	cout << getPath(N - 1, M - 1);
	return 0;
}