#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NUM 1987654321
map<int, int>adj[1001]; //연결된 정점, 가중치
vector<int>dist(1001, MAX_NUM); //최단거리 저장
int V, E;

void dijkstra(int start) { //노드 확장이거나, 노드 값 변경임
	dist[start] = 0;
	//거리 가까운 것 먼저 나온다
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //거리, 정점
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (auto it = adj[here].begin(); it != adj[here].end(); it++) {
			int there = it->first;
			int nextDist = cost + it->second;
			if (dist[there] > nextDist) { //더 짧은 경로면, 갱신 후 대기열에 삽입
				dist[there] = nextDist;
				pq.push({ nextDist, there });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int X, u, v, w;
	cin >> V >> E >> X;

	while (E-- > 0) {
		cin >> u >> v >> w;
		adj[u][v] = w;
	}

	vector<int> arr(V);
	arr.push_back(0);
	
	for (int i = 1; i <= V; i++) {
		dijkstra(i);
		arr[i] = dist[X];
		for (int i = 1; i <= V; i++)
			dist[i] = MAX_NUM;
	}
	dijkstra(X);
	
	int ans = 0;
	for (int i = 1; i <= V; i++) {
		arr[i] += dist[i];
		ans = max(ans, arr[i]);
	}
	cout << ans;

	return 0;
}