#include <iostream>
#include <vector>
using namespace std;

int adj[1001][6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i<= N; i++) //��ȣ
		for (int j = 1; j <= 5; j++) //�г�
			cin >> adj[i][j];
	
	int ans=1, max_friend = 0;
	for (int i = 1; i <= N; i++) { //��ȣ
		int tmp = 0;
		for (int p = 1; p <= N; p++) {
			for (int q = 1; q <= 5; q++) {
				if (adj[i][q] == adj[p][q]) {
					tmp++;
					break;
				}
			}
		}
		if (tmp > max_friend) {
			max_friend = tmp;
			ans = i;
		}
	}

	cout << ans;
	return 0;
}