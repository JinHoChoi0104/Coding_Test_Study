#include <iostream>
using namespace std;

#define MAX_RANGE 100
int arr[MAX_RANGE + 1] = { 9,1,4,5,7,2 };
int tree[(MAX_RANGE + 1) * 4];

int init(int l, int r, int index) { //Storing data's sum in the segment tree
	if (l == r) return tree[index] = arr[l];
	int mid = (l + r) / 2;

	return tree[index] = init(l, mid, index * 2) + init(mid + 1, r, index * 2 + 1);
}

int query(int l, int r, int index, int start, int end) { //Returen sum of given range
	if (start > r || end < l) return 0;
	if (start <= l && end >= r) return tree[index];
	int mid = (l + r) / 2;
	return query(l, mid, index * 2, start, end) + query(mid + 1, r, index * 2 + 1, start, end);
}

int main() {
	arr[MAX_RANGE] = 987654321;
	init(0, 5, 1);

	cout << "arr[]: ";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++)
			cout << "[" << i << ", " << j << "] index: " << query(0, 5, 1, i, j) << " => " << query(0, 5, 1, i, j)<< endl;

	return 0;
}