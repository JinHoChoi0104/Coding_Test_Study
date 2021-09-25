#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NUM 987654321
map<int, int>adj[20001]; //����� ����, ����ġ
vector<int>dist(20001, MAX_NUM); //�ִܰŸ� ����
int V, E;

void dijkstra(int start) { //��� Ȯ���̰ų�, ��� �� ������
	dist[start] = 0;
	//�Ÿ� ����� �� ���� ���´�
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq; //�Ÿ�, ����
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (auto it = adj[here].begin(); it != adj[here].end(); it++) {
			int there = it -> first;
			int nextDist = cost + it -> second;
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
	cin >> V >> E;
	int start, u, v, w;
	cin >> start;
	while (E-- > 0) {
		cin >> u >> v >> w;
		if (adj[u].find(v) != adj[u].end()) //�̹� �ִ� ���
			adj[u][v] = min(adj[u][v], w);
		else
			adj[u][v] = w;
	}
	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == MAX_NUM) {
			cout << "INF\n";
			continue;
		}
		cout << dist[i] <<"\n";
	}
	return 0;
}