#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. merge sort ���� ����
�պ������� ������ �ƴ��� �ľ� �� �� �ܰ������ �����ϸ� �ȴ�.
������ �����ϴ� �ο��� N/2�� ���� �� �ܰ谡 ���� �� �� ���� ������ �پ���.

2. ���� ������ ����
������ �ϴ� �ο��� K���̸� �� �� N/K���� ���Ҹ� ���� �Ѵٴ� ���̴�.
�� ������ ��ŭ�� ���� ���ָ� �ȴ�.
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
	K = N / K; //�� �� �����ϴ� ������ ����
	for (int i = 0; i < N; i += K)
		sort(arr.begin() + i, arr.begin() + i + K);
	for (auto it = arr.begin(); it != arr.end(); it++)
		printf("%d ", *it);
	return 0;
}