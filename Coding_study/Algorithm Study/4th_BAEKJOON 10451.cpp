#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, N, num;
	for (cin >> T; T-- > 0;) {
		cin >> N;
		vector<int> v(N + 1);
		vector<bool> visited(N + 1, false);
		for (int i = 1; i <= N; i++) 
			cin >> v[i];
		
		queue<int>q;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) { //�湮���� ������ Ž�� ����
				cnt++;
				q.push(v[i]);
				visited[i] = true;
				while (!q.empty()) { //�̾��� ���� ���� Ž��
					num = q.front();
					visited[num] = true;
					q.pop();
					if (!visited[v[num]]) 
						q.push(v[num]);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}