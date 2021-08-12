#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr(9);
void NM(int index, vector<int>a) {
	a.push_back(arr[index]);
	if (a.size() == M + 1) {
		for (int i = 1; i <= M; i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = index + 1; i <= N; i++)
		NM(i, a);
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.begin() + N + 1);
	vector<int>a;
	NM(0, a);

	return 0;
}