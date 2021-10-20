#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NUM 1987654321
map<int, int>adj[10001]; //����� ����, ����ġ
vector<int>dist(10001, MAX_NUM); //�ִܰŸ� ����
int V, E;

void dijkstra(int start) { //��� Ȯ���̰ų�, ��� �� ������
	dist[start] = 0;
	//�Ÿ� ����� �� ���� ���´�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //�Ÿ�, ����
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (auto it = adj[here].begin(); it != adj[here].end(); it++) {
			int there = it->first;
			int nextDist = cost + it->second;
			if (dist[there] > nextDist) { //�� ª�� ��θ�, ���� �� ��⿭�� ����
				dist[there] = nextDist;
				pq.push({ nextDist, there });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, start;
	for (cin >> T; T-- > 0;) {
		cin >> V >> E >> start;
		for (int i = 1; i <= V; i++) {
			dist[i] = MAX_NUM;
			adj[i].clear();
		}
		int u, v, w;
		while (E-- > 0) {
			cin >> v >> u >> w;
			adj[u][v] = w;
		}
		dijkstra(start);
		int ans = 0, cnt = 0;
		for (int i = 1; i <= V; i++) {
			if (dist[i] != MAX_NUM) {
				cnt++;
				ans = max(ans, dist[i]);
			}
		}
		cout << cnt << " " << ans << "\n";
	}

	return 0;
}