#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, a, b;
	int arr[4] = { 0,1,2,3 };
	for (cin >> T; T-- > 0; ) {
		cin >> a >> b;
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	for (int i = 1; i <= 3; i++)
		if (arr[i] == 1)
			cout << i;

	return 0;
}