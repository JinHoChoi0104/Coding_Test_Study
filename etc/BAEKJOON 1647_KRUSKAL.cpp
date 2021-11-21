#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct OptimizedDisjointSet {
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]); //경로 압축
	}

	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return; //같은 소속이면 합치지 않는다
		if (rank[u] > rank[v]) swap(u, v); //v의 랭크(높이)가 더 커지게 한다.
		parent[u] = v; //u를 v의 자식으로 넣는다.
		if (rank[u] == rank[v]) rank[v]++;
	}
};

int V; //노드 개수
vector<pair<int, pair<int, int>>> edges;
int kruskal() {
	int ans = 0, cnt = 0; //길 유지비, 포함 된 집의 수
	sort(edges.begin(), edges.end()); // 가중치의 크기에 따라 오름차순 정렬

	OptimizedDisjointSet sets(V + 1);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.find(u) == sets.find(v)) continue; //u와 v가 같은 소속이면 패스
		sets.merge(u, v);
		ans += cost;
		cnt++;
		if (cnt == V - 2) //필요한 간선은 '전체 노드 - 2개'이다.
			break;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int E, u, v, cost;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> cost;
		edges.push_back({ cost, { u, v } });
	}

	cout << kruskal();
	return 0;
}