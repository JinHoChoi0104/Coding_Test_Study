#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	char c[101][101];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> c[i][j];
	int p, q;
	cin >> p >> q;
	
	for (int i = 0; i < n; i++) 
		for (int j = m; j < m * 2; j++) 
			c[i][j] = c[i][2 * m - j - 1];
	for (int i = n; i < n * 2; i++) 
		for (int j = 0; j < m * 2; j++) 
			c[i][j] = c[2 * n - i - 1][j];
		
	if (c[p - 1][q - 1] == '#')
		c[p - 1][q - 1] = '.';
	else
		c[p - 1][q - 1] = '#';

	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < m * 2; j++)
			cout << c[i][j];
		cout << "\n";
	}
	
	return 0;
}