#include<iostream>
#include<algorithm>
using namespace std;
// Sutdying LIS (Longest Increasing Subsequence)

int n;
int cache[100], S[100];

// S[start]���� �����ϴ� ���� �κ� ���� �� �ִ� ���̸� ��ȯ�Ѵ�.
int list(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	//�׻� S[start]�� �ֱ� ������ ���̴� ���� 1
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (S[start] < S[next])
			ret = max(ret, lis2(next) + 1);
		return ret;
	}
}

int main(void) {

	return 0;
}