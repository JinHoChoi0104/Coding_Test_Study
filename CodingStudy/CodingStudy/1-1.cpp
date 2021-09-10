#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 987654321, total = 0, arr[20][20];

void geri(int x, int y) {
	int d1 = min(y, N - 2 - x);
	int d2 = min(N -1 - y, N - 2 - x);

	for (int i = 1; i <= d1; i++) {
		for (int j = 1; j <= d2; j++) {
			vector <int> v(5, 0);
			vector<int>line[4];
			for (int l = 0; l < x; l++) {
				line[0].push_back(0);
				line[1].push_back(0);
			}
			for (int l = 1; l <= i; l++)
				line[0].push_back(l);
			for (int l = 0; l <= j; l++)
				line[1].push_back(l);
			for (int l = j; l >= 0; l--)
				line[2].push_back(l);
			for (int l = i; l >= 1; l--)
				line[3].push_back(l);
			for (int l = x + i + j + 1; l < N; l++) {
				line[2].push_back(0);
				line[3].push_back(0);
			}

			for (int r = 0; r < x + i; r++)
				for (int c = 0; c <= y - line[0][r]; c++)
					v[0] += arr[r][c];
			for (int r = 0; r <= x + j; r++)
				for (int c = y+1+line[1][r]; c < N; c++)
					v[1] += arr[r][c];
			for (int r = x + i; r < N; r++)
				for (int c = 0; c < y - i + j - line[2][r-x-i]; c++)
					v[2] += arr[r][c];
			for (int r = x + j + 1; r < N; r++)
				for (int c = y-i+j + line[3][r - x - j - 1]; c < N; c++)
					v[3] += arr[r][c];
			v[4] = total - v[0] - v[1] - v[2] - v[3];
			sort(v.begin(), v.end());
			ans = min(ans, v[4] - v[0]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			total += arr[i][j];
		}		
	for (int i = 0; i <= N - 3; i++)
		for (int j = 1; j <= N - 2; j++) 
			geri(i, j);
		
	cout << ans;
	return 0;
}