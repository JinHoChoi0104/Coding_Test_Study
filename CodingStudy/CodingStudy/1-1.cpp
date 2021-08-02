#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector <pair<int, int>> arr(1401); //weight, value
vector <vector <int>> dp(10001, vector<int>(1401, -1)); //load weight, index
// max value when [loaded weight][index ~ end]

//returning max value, pick items from index to end, and when remain weight is 'capacity'
int bagPacking(int capacity, int index) {
	if (index == N) return 0;
	int& ret = dp[capacity][index];
	if (ret != -1) //if already have answer
		return ret;
	ret = bagPacking(capacity, index + 1);
	if (capacity >= arr[index].first)
		ret = max(ret, bagPacking(capacity - arr[index].first, index + 1) + arr[index].second);
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	int v, c, k, j = 0, max_val = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &v, &c, &k);
		
		while (k > 3) {
			arr[j].first = v * (int)(k / 2), arr[j++].second = c * (int)(k / 2);
			if (k % 2 == 1)
				k = k / 2 + 1;
			else
				k = k / 2;
		}
		if (k == 3) 
			arr[j].first = v * 2, arr[j++].second = c * 2;
		else if (k == 2) 
			arr[j].first = v, arr[j++].second = c;
		arr[j].first = v, arr[j++].second = c;
	}
	N = j;

	for (int i = 0; i <= K; i++)
		max_val = max(max_val, bagPacking(i, 0));

	printf("%d", max_val);
}