#include<iostream>
#include<algorithm>
using namespace std;
// Sutdying LIS (Longest Increasing Subsequence)

int n;
int cache[100], S[100];

// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int list(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	//항상 S[start]는 있기 때문에 길이는 최하 1
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