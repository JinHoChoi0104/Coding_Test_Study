#include <iostream>
using namespace std;

#define MAX_RANGE 100
int arr[MAX_RANGE + 1] = {9,1,4,5,7,2};
int tree[(MAX_RANGE+1)*4];

int init(int l, int r, int index) { //Storing data in the segment tree
	int& ret = tree[index];
	if (l == r)
		return ret = l;

	int mid = (l + r) / 2;
	int lindex = init(l, mid, index * 2);
	int rindex = init(mid + 1, r, index * 2 + 1);

	return ret = arr[lindex] < arr[rindex] ? lindex : rindex;
}

int query(int l, int r, int index, int start, int end) { //Returen index of lowest number above given range
	if (r < start || end < l)
		return MAX_RANGE;
	if (start <= l && end >= r)
		return tree[index];

	int mid = (l + r) / 2;
	int lindex = query(l, mid, index * 2, start, end);
	int rindex = query(mid + 1, r, index * 2 + 1, start, end);

	if (arr[lindex] > arr[rindex])
		return rindex;
	else
		return lindex;
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
			cout << "[" << i << ", " << j << "] index: " << query(0, 5, 1, i, j) << " => " << arr[query(0, 5, 1, i, j)] << endl;
	
	return 0;
}