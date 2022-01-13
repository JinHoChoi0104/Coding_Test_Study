#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m, num, arr[500][500];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			int cnt = 0;
			while (num > 0) {
				if (num % 10 == 9)
					cnt++;
				num /= 10;
			}
			arr[i][j] = cnt;
		}
	}
	int total = 0, max_num = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < m; j++) 
			tmp += arr[i][j];
		total += tmp;
		max_num = max(max_num, tmp);
	}
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++)
			tmp += arr[j][i];
		max_num = max(max_num, tmp);
	}
	
	cout << total - max_num;
	return 0;
}