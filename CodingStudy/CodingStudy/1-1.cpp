#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, max_i = 0;
vector<int> a(500, -1);
vector<int> cache(500, -1); //save lis starting at i

int lis(int start) {
	int &ret = cache[start];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = start+1; i <= max_i; i++) {
		if (a[start] < a[i])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	int from, to;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &from, &to);
		a[from] = to;
		max_i = max(max_i, from);
	}

	/*
	by putting -1 (minimul than all ather elements) in to infront of array
	a[0] = -1
	cache(0) - 1 (which is lis(0) - 1) is LIS of total array
	*/
	// (total power code) - (remaining code) = (removed code) 
	printf("%d", N - (lis(0) - 1));
	return 0;
}