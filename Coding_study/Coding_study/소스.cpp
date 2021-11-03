#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_RANGE 300000
vector<int> arr;
vector<int> tree((MAX_RANGE+1) * 4);

int init(int l, int r, int index) {
	int &ret = tree[index];
	if (l == r)
		return ret = arr[l];
	int mid = (l + r) / 2;
	return ret = init(l, mid, index * 2) + init(mid + 1, r, index * 2 + 1);
}

int getRangeSum(int l, int r, int index, int start, int end) {
	if (start > r || end < l) return 0; //범위 벗어나면 0
	if (start <= l && end >= r) return tree[index]; //범위 안이면 리턴
	int mid = (l + r) / 2;
	return getRangeSum(l, mid, index * 2, start, end) + getRangeSum(mid + 1, r, index * 2 + 1, start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, Q, num;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	init(0, N-1, 1);
	while (Q-- > 0) {
		int to, from;
		cin >> to >> from;
		cout << getRangeSum(0, N-1, 1, to-1, from-1) << "\n";
	}

	return 0;
}