#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp(500, vector<int>(500, -1));
// dp[i][j] = i에서 j까지의 파일을 합치는데 필요한 최소 비용
vector<int> sum(500);
// 0에서 j까지의 파일크기 합 저장
vector<int> arr(500);
// 파일 크기 저장

int main() {
	int T, N;
	scanf("%d", &T);
	sum[0] = 0;
	while (T--) {
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			sum[i + 1] = sum[i] + arr[i];
			dp[i][i] = 0; //파일 1개는 합치는 비용이 0이다
		}
		for (int len = 2; len <= N; len++) { //파일이 len개일 때의 최소값을 구한다
			for (int i = 0; i <= N - len; i++) {
				int &ret = dp[i][i-1+len];
				ret = 2147483647; //int 최대값
		
				for (int j = i; j < i + len - 1; j++) 
					ret = min(ret, dp[i][j] + dp[j + 1][i + len - 1]);
				// 파일을 합칠 수 있는 모든 경우의 수들 중 최소를 찾는다

				ret += (sum[i + len] - sum[i]); //l에서 r까지 파일크기 합

				//l에서 r까지의 파일을 합치는데 필요한 최소 비용 = l에서 r까지 파일크기 합 + 이전 단계의 파일 2개를 만드는 데 필요합 비용의 합
			}
		}
		// 0, N-1
		printf("%d\n", dp[0][N - 1]);
	}
}