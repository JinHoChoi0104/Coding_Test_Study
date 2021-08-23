#include <iostream>
#include <vector>
using namespace std;

vector<int>arr1(100000);
vector<int>arr2(100000);
vector<int>ans(100000);
int N, index = 0;

void find_root(int l1, int r1, int l2, int r2) {
	ans[index++] = arr2[r2];
	if (r1 - l1 < 2) {
		if (r1 - l1 == 1)
			ans[index++] = arr2[r2 - 1];
		return;
	}
	int k = r1;
	while (1) {
		if (arr1[k] == arr2[r2])
			break;
		else
			k--;
	}
	int k2 = r2;
	while (k != r1) { // if there is no child on the right
		if (arr2[k2] == arr1[k + 1])
			break;
		else
			k2--;
	}

	if (l1 <= k - 1 && l2 <= k2 - 1)
		find_root(l1, k - 1, l2, k2 - 1); //left child 
	if (k + 1 <= r1 && k2 <= r2 - 1)
		find_root(k + 1, r1, k2, r2 - 1); //right child

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr1[i];

	for (int i = 0; i < N; i++)
		cin >> arr2[i];

	find_root(0, N - 1, 0, N - 1);

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	return 0;
}