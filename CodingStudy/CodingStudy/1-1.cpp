#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
Knuth's optimization

dp[i][j] = min (dp[i][k]+dp[k][j]) + sum[i + 1][j]
=>
dp[i][j]�� (i+1)���� j������ ������ ��ġ�µ� �ʿ��� �ּ� ����̴�
�� ���� dp[i][k] (i+1 ���� k����), dp[k][j] (k+1���� j����)�� �յ� �� �ּ� ��
+
sum[i+1][j]�̴� ( i+1���� j������ �� )

�̶� k�� ������
dp[i][j-1] �� dp[i+1][j]�� �ּҰ��� ������ k
=> A[i][j-1] �� A[i+1][j] ���̿� �ִ�.
��
A[i][j-1] <= A[i][j] <= A[i+1][j]

*/

vector<vector<int>> dp(501, vector<int>(501));
// dp[i][j] = (i + 1)���� j������ ������ ��ġ�µ� �ʿ��� �ּ� ���
vector<vector<int>> A(501, vector<int>(501));
// A[i][j] = dp[i][j] �� �ּڰ��� ������ ���� k
vector<int> sum(501);
// 0���� j������ ����ũ�� �� ����

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

		for (int len = 3; len <= N; len++) { //������ len���� ���� �ּҰ��� ���Ѵ�
			for (int i = 0; i <= N - len; i++) { // len�� 2�� ��� ���ؾ� �ϴ°� dp[0][2], dp[1][3], dp[2][4]....dp[n-2][n]�ణ i�ʰ� j���� ����!
				int &ret = dp[i][i+len];
				ret = 2147483647; //int �ִ밪
				for (int k = A[i][i + len - 1]; k <= A[i + 1][i + len]; k++) //k�� ������ �� �ܰ谡 ������ k 2�� ���̿� �ִ�
					if (ret > dp[i][k] + dp[k][i + len]) {
						ret = dp[i][k] + dp[k][i + len];
						A[i][i + len] = k;
					}
				
				// �� �� �ּҸ� ã�´�
				ret += (sum[i + len] - sum[i]); //(i + 1)���� (i + len)������ ����ũ�� ��
				//(i+1)���� (i+len)������ ������ ��ġ�µ� �ʿ��� �ּ� ��� = (i+1)���� (i+len)���� ����ũ�� �� + ���� �ܰ��� ���� 2���� ����� �� �ʿ��� ����� ��
			}
		}
		printf("%d\n", dp[0][N]);
	}
	return 0;
}