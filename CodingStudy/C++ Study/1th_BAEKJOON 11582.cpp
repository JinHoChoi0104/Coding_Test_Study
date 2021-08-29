#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. merge sort 직접 구현
합병정렬이 어디까지 됐는지 파악 후 그 단계까지만 진행하면 된다.
정렬을 진행하는 인원은 N/2로 실행 후 단계가 진행 될 때 마다 반으로 줄어든다.

2. 구간 나눠서 구현
정렬을 하는 인원이 K명이면 인 당 N/K개의 원소를 정렬 한다는 뜻이다.
그 갯수씩 만큼만 정렬 해주면 된다.
*/
int main() {
	int N, K, num;
	scanf("%d", &N);
	vector<int>arr;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr.push_back(num);
	}
	scanf("%d", &K);
	K = N / K; //인 당 정렬하는 원소의 개수
	for (int i = 0; i < N; i += K)
		sort(arr.begin() + i, arr.begin() + i + K);
	for (auto it = arr.begin(); it != arr.end(); it++)
		printf("%d ", *it);
	return 0;
}