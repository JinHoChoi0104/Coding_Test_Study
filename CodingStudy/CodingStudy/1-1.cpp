#include<iostream>
#include<algorithm>
using namespace std;
// Sutdying LIS (Longest Increasing Subsequence)
// Studying with book '프로그래밍 대회에서 배우는 알고리즘 문제 해결 전략'
int n;
int cache[1000], S[1000];

// return LIS starts from S[start] (and this includes S[start])
int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret; //if LIS for start has been answered immediately return

	// since S[start] is always at there, LIS should be at least 1
	ret = 1;
	for (int next = start + 1; next < n; ++next) 
		if (S[start] < S[next])
			ret = max(ret, lis2(next) + 1);
	
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &S[i]);
		cache[i] = -1;
	}
	int max_lis = 0;
	for (int i = 0; i < n; i++) 
		max_lis = max(max_lis, lis2(i));

	cout << max_lis;
	return 0;
}