#include <iostream>
#include <vector>

using namespace std;
vector<int> tree(400004), arr(100001);

int init(int l, int r, int index) {
	if (l == r) return tree[index] = arr[l];
	int mid = (l + r) / 2;
	
	return tree[index] = init(l, mid, index * 2) + init(mid + 1, r, index * 2 + 1);
}
int sum(int l, int r, int index, int from, int to) {
	if (from > r || to < l) return 0;
	if (from <= l && to >= r) return tree[index];
	int mid = (l + r) / 2;
	return sum(l, mid, index * 2, from, to) + sum(mid+1, r, index * 2 + 1, from, to);
}
int main() {
	int N, M, a ,b;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);
	init(0, N-1, 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sum(0,N-1,1,a-1,b-1));
	}
	return 0;
}