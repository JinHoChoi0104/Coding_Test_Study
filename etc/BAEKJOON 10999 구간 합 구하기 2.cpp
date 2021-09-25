#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<ll> tree(4000005), arr(1000001);

ll init(int l, int r, int index) {
	if (l == r) return tree[index] = arr[l];
	int mid = (l + r) / 2;

	return tree[index] = init(l, mid, index * 2) + init(mid + 1, r, index * 2 + 1);
}
ll sum(int l, int r, int index, int from, int to) {
	if (from > r || to < l) return 0;
	if (from <= l && to >= r) return tree[index];
	int mid = (l + r) / 2;
	return sum(l, mid, index * 2, from, to) + sum(mid + 1, r, index * 2 + 1, from, to);
}

//num: amount of change, from & to: range of number which will be modified
ll modify(int l, int r, int index, ll num, int from, int to) {
	if (from > r || to < l) return 0;
	if (l == r) { 
		tree[index] += num;
		return 1; 
	}

	int mid = (l + r) / 2;
	//count how many numbers have been modified
	ll cnt = modify(l, mid, index * 2, num, from, to) + modify(mid + 1, r, index * 2 + 1, num, from, to);
	tree[index] += num * cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, M, K, mode;
	ll a, b, c;
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	init(0, N - 1, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> mode; 
		if (mode == 1) {
			cin >> a >> b >> c;
			modify(0, N - 1, 1, c, a - 1, b - 1);
			//for (int j = a - 1; j <= b - 1; j++)
			//	arr[j] += c;
		}
		else {
			cin >> a >> b;
			cout << sum(0, N - 1, 1, a - 1, b - 1) << "\n";
		}
	}
	return 0;
}