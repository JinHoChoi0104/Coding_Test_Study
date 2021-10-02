#include <iostream>
#include <vector>
using namespace std;
vector<int> tree(400005, 0), lazy(400005, -1);
//lazy = -1: not changing state, 1: change state

void propagationLazy(int l, int r, int index) {
	if (lazy[index] == 1) { //if you have to change state
		int& ret = tree[index];
		ret = r - l + 1 - ret; //adjust lazy

		if (l != r)
			lazy[index * 2] *= -1, lazy[index * 2 + 1] *= -1; //give lazy to two childs
		
		lazy[index] = -1;
	}
}

int sum(int l, int r, int index, int from, int to) {
	propagationLazy(l, r, index);
	if (from > r || to < l) return 0;
	if (from <= l && to >= r) return tree[index];
	int mid = (l + r) / 2;
	return sum(l, mid, index * 2, from, to) + sum(mid + 1, r, index * 2 + 1, from, to);
}

//num: amount of change, from & to: range of number which will be modified
void modify(int l, int r, int index, int from, int to) {
	propagationLazy(l, r, index);
	
	if (from > r || to < l) return; //out of range

	int& ret = tree[index];
	if (from <= l && r <= to) { //if totally in range
		ret = r - l + 1 - ret;
		if (l != r)
			lazy[index * 2] *= -1, lazy[index * 2 + 1] *= -1;
		return;	
	}

	int mid = (l + r) / 2;
	modify(l, mid, index * 2, from, to);
	modify(mid + 1, r, index * 2 + 1, from, to);

	ret = tree[index * 2] + tree[index * 2 + 1];
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N;

	int mode, from, to;
	for (cin >> M; M-- > 0;) {
		cin >> mode >> from >> to;
		if (mode == 0)  //Update
			modify(0, N - 1, 1, from - 1, to - 1);
		else  //get Range Sum
			cout << sum(0, N - 1, 1, from - 1, to - 1) << "\n";
	}

	return 0;
}