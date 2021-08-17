#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp(500, vector<int>(500, -1));
// dp[i][j] = i���� j������ ������ ��ġ�µ� �ʿ��� �ּ� ���
vector<int> sum(500);
// 0���� j������ ����ũ�� �� ����
vector<int> arr(500);
// ���� ũ�� ����

int main() {
	int T, N;
	scanf("%d", &T);
	sum[0] = 0;
	while (T--) {
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			sum[i + 1] = sum[i] + arr[i];
			dp[i][i] = 0; //���� 1���� ��ġ�� ����� 0�̴�
		}
		for (int len = 2; len <= N; len++) { //������ len���� ���� �ּҰ��� ���Ѵ�
			for (int i = 0; i <= N - len; i++) {
				int &ret = dp[i][i-1+len];
				ret = 2147483647; //int �ִ밪
		
				for (int j = i; j < i + len - 1; j++) 
					ret = min(ret, dp[i][j] + dp[j + 1][i + len - 1]);
				// ������ ��ĥ �� �ִ� ��� ����� ���� �� �ּҸ� ã�´�

				ret += (sum[i + len] - sum[i]); //l���� r���� ����ũ�� ��

				//l���� r������ ������ ��ġ�µ� �ʿ��� �ּ� ��� = l���� r���� ����ũ�� �� + ���� �ܰ��� ���� 2���� ����� �� �ʿ��� ����� ��
			}
		}
		// 0, N-1
		printf("%d\n", dp[0][N - 1]);
	}
}