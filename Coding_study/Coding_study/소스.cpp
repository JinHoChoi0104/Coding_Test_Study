#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define DIVIDNG_NUM 1000000007
vector<ll> arr(1000001), tree(4000005, 0);

ll init(int l, int r, int index) {
	ll& ret = tree[index];
	if (l == r) return ret = arr[l]; //leaf node
	int mid = (l + r) / 2;
	return ret = (init(l, mid, index * 2) * init(mid + 1, r, index * 2 + 1)) % DIVIDNG_NUM;
}

ll mul(int l, int r, int index, int from, int to) {
	if (from > r || to < l) return 1;
	if (from <= l && to >= r) return tree[index];
	int mid = (l + r) / 2;
	return (mul(l, mid, index * 2, from, to) * mul(mid + 1, r, index * 2 + 1, from, to)) % DIVIDNG_NUM;
}

//value: amount of change, target: index of number which will be modified
ll modify(int l, int r, int index, int target, int value) {
	ll& ret = tree[index];
	if (target > r || target < l) return ret; //out of range
	if (l == r) {
		arr[target] = value;
		ret = arr[target];
		return ret;
	}
	int mid = (l + r) / 2;
	return ret = (modify(l, mid, index * 2, target, value) * modify(mid + 1, r, index * 2 + 1, target, value)) % DIVIDNG_NUM;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(0, N - 1, 1);

	int mode, a, b;
	for (int i = 0; i < M + K; i++) {
		cin >> mode >> a >> b;
		if (mode == 1)  //Update
			modify(0, N - 1, 1, a - 1, b);
		else  //get Range Multiple
			cout << mul (0, N - 1, 1, a - 1, b - 1) << "\n";
	}

	return 0;
}