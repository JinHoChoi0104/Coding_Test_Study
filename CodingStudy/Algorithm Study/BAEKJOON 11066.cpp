#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> dp(500, vector<int>(500, -1)); 
// dp[i][j] = i���� j������ ������ ��ġ�µ� �ʿ��� �ּ� ���
vector<int> arr(500);
// ���� ũ�� ����

int merging(int l, int r){ //���� ����!
	int& ret = dp[l][r];
	if (ret != -1) //���� �̹� ���� ���
		return ret;

	ret = 0;
	for (int i = l; i <= r; i++) //l���� r���� ����ũ�� ��
		ret += arr[i];
	int num = 2147483647; //int �ִ밪
	for (int i = l; i < r; i++) 
		num = min(num, merging(l, i) + merging(i + 1, r)); // ������ ��ĥ �� �ִ� ��� ����� ���� �� �ּҸ� ã�´�
	
	ret += num; 
	//l���� r������ ������ ��ġ�µ� �ʿ��� �ּ� ��� = l���� r���� ����ũ�� �� + ���� �ܰ��� ���� 2���� ����� �� �ʿ��� ����� ��
	return ret;
}


int main() {
	//freopen("input.txt", "r", stdin);
	int T, num;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				dp[i][j] = -1;
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			dp[i][i] = 0; //���� 1���� ��ġ�� ����� 0�̴�
		}

		printf("%d\n", merging(0, N - 1));
	}
}