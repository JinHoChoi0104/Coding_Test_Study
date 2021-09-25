#include <iostream>
#include <vector>

using namespace std;

#define DIV 998244353

int main(void) {
	int N, num;
	scanf("%d", &N);

	vector<int>arr(N); //A�� ���� ����
	vector<long long>dp(N, 1); //overflow ������ long long���� ����
	/*
	����) arr[1] �� arr[2] ���� arr[3��] Ŭ ���
	dp[1]�� arr[1]�� ������ �����Ѵ�, �׷��� arr[2]�� �������� �ʴ´�
	dp[2]�� arr[2]�� ������ �����Ѵ�
	��, dp[1]�� dp[2]�� ���� ��ġ�� ��찡 ���� ���� �����̴�

	�̰��� �̿��� dp[3]�� �ܼ��� dp[1]�� ��� ��쿡 arr[3]�� �ڿ� ���̰�, ���������� dp[2]���� arr[3]�� �ٿ��ش�.
	�� �� ������ ��쵵 �տ����� ���� ���������̴�
	���������� arr[3] ȥ�� �ִ� ��쵵 ������, dp[3]�� 1�� �����ش�.
	*/
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i]) //�տ� �ִ� ������ �� ũ�ٸ� �� �� ������ arr[i]�� ���� �� �ִ�.
				dp[i] += dp[j]; //�� �������� int ������ �ʰ��� ��� overflow �߻��Ѵ�
		dp[i] %= DIV;
	}

	for (int i = 0; i < N; i++)
		printf("%lld ", dp[i]);

	return 0;
}