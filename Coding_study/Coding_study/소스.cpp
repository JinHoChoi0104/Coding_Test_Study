#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	char ch[50][50];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> ch[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < r; x++) {
			for (int j = 0; j < m; j++) {
				for(int y = 0; y < c; y++)
					cout << ch[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}