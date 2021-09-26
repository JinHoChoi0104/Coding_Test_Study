#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, ans = 0;
	vector<int> adj[50];
	char c;
	
	cin >> N;
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			cin >> c;
			if (c == 'Y') {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}

	for (int i = 0; i < N; i++) {
		vector<bool> visited(N, false);
		int cnt = -1; //�ڱ� �ڽ��� ���� �ϱ� ���� -1
		for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
			if (!visited[*it]) { //�׳� ģ��
				cnt++;
				visited[*it] = true;
			}
			for(auto it2 = adj[*it].begin(); it2 != adj[*it].end(); it2++)
				if (!visited[*it2]) { //2- ģ��
					cnt++; //���⼭ �ڱ� �ڽŵ� ģ���� ġ�� ��
					visited[*it2] = true;
				}
		}
		ans = max(ans, cnt); //�ִ� ã��
	}
	cout << ans;
	return 0;
}