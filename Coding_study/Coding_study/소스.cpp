#include <iostream>
using namespace std;

char map[50][50];
bool visited[50][50];
int main(){
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j])
				continue;
			cnt++;
			if (map[i][j] == '-') {
				while (map[i][j] == '-') {
					visited[i][j++] = true;
					if (j == m)
						break;
				}
				j--;
			}
			else {
				int tmp = i;
				while (map[tmp][j] == '|') {
					visited[tmp++][j] = true;
					if (tmp == n)
						break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
} 