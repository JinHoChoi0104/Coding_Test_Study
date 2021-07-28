#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void binarySearch(int l, int r, int num, vector<int>& note1) {
	if (l > r) {
		printf("0\n");
		return;
	}
	int mid = (l + r) / 2;

	if (num == note1[mid])
		printf("1\n");
	else if (num < note1[mid])
		binarySearch(l, mid - 1, num, note1);
	else if (num > note1[mid])
		binarySearch(mid + 1, r, num, note1);
}

int main(void) {
//	freopen("input.txt", "r", stdin);
	int T, N, M, num;
	scanf("%d", &T);

	while (T--) {
		vector<int> note1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			note1.push_back(num);
		}
		sort(note1.begin(), note1.end());

		scanf("%d", &M);
		while (M--) {
			scanf("%d", &num);
			binarySearch(0, N - 1, num, note1);
		}
	}
	return 0;
}