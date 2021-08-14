#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
Knuth's optimization

dp[i][j] = min (dp[i][k]+dp[k][j]) + sum[i + 1][j]
=>
dp[i][j]는 (i+1)에서 j까지의 파일을 합치는데 필요한 최소 비용이다
이 값은 dp[i][k] (i+1 에서 k까지), dp[k][j] (k+1에서 j까지)의 합들 중 최소 값
+
sum[i+1][j]이다 ( i+1에서 j까지의 합 )

이때 k의 범위는
dp[i][j-1] 와 dp[i+1][j]가 최소값을 가지는 k
=> A[i][j-1] 와 A[i+1][j] 사이에 있다.
즉
A[i][j-1] <= A[i][j] <= A[i+1][j]

*/

vector<vector<int>> dp(501, vector<int>(501));
// dp[i][j] = (i + 1)에서 j까지의 파일을 합치는데 필요한 최소 비용
vector<vector<int>> A(501, vector<int>(501));
// A[i][j] = dp[i][j] 가 최솟값을 가지기 위한 k
vector<int> sum(501);
// 0에서 j까지의 파일크기 합 저장

int main() {
	int T, N, pre, num;
	scanf("%d", &T);
	sum[0] = 0;
	while (T--) {
		scanf("%d", &N);
		scanf("%d", &pre);
		sum[1] = pre;
		for (int i = 2; i <= N; i++) {
			scanf("%d", &num);
			sum[i] = sum[i-1] + num;

			A[i - 2][i] = i - 1;
			dp[i - 2][i] = pre + num;
			pre = num;
		}

		for (int len = 3; len <= N; len++) { //파일이 len개일 때의 최소값을 구한다
			for (int i = 0; i <= N - len; i++) { // len가 2일 경우 구해야 하는건 dp[0][2], dp[1][3], dp[2][4]....dp[n-2][n]약간 i초과 j이하 범위!
				int &ret = dp[i][i+len];
				ret = 2147483647; //int 최대값
				for (int k = A[i][i + len - 1]; k <= A[i + 1][i + len]; k++) //k의 범위는 전 단계가 가지는 k 2개 사이에 있다
					if (ret > dp[i][k] + dp[k][i + len]) {
						ret = dp[i][k] + dp[k][i + len];
						A[i][i + len] = k;
					}
				
				// 그 중 최소를 찾는다
				ret += (sum[i + len] - sum[i]); //(i + 1)에서 (i + len)까지의 파일크기 합
				//(i+1)에서 (i+len)까지의 파일을 합치는데 필요한 최소 비용 = (i+1)에서 (i+len)까지 파일크기 합 + 이전 단계의 파일 2개를 만드는 데 필요합 비용의 합
			}
		}
		printf("%d\n", dp[0][N]);
	}
	return 0;
}