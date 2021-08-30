#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp(500, vector<int>(500)); //save minimum number of multiplication operations
int arr[2][500]; //r c
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &arr[0][i]);
		scanf("%d", &arr[1][i]);
		dp[i][i] = 0;
	}
	
	for (int i = 1; i < N; i++) { //i = [number of elements that going to be calculated] - 1
		for (int j = 0; j < N - i; j++) { //index to start
			dp[j][j + i] = 2147483647;
			int tmp;
			for (int k = j; k < j + i; k++) {
				tmp = dp[j][k] + dp[k + 1][j + i] + arr[0][j] * arr[1][k] * arr[1][j + i];
				dp[j][j + i] = min(tmp, dp[j][j + i]);
			}
		}
	}
	printf("%d", dp[0][N - 1]);
	return 0;
}