#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector <pair<int, int>> arr(100001); //weight, value
vector <vector <int>> dp(100001, vector<int>(101,-1)); //loade weight, index
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
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	int w, v, max_val = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &w, &v);
		arr[i].first = w, arr[i].second = v;
	}
	
	for (int i = 0; i <= K; i++) {
		printf("%d: %d\n", i, bagPacking(i, 0));
		max_val = max(max_val, bagPacking(i, 0));
	}
	printf("%d", max_val);
}