#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int arr[300][300];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	int t, x1, y1, x2, y2;
	for (cin >> t; t-- > 0;) {
		cin >> x1 >> y1 >> x2 >> y2;
		int tmp = 0;
		for (int i = x1-1; i < x2; i++) {
			for (int j = y1-1; j < y2; j++) {
				tmp += arr[i][j];
			}
		}
		cout << tmp << "\n";
	}
	return 0;
}