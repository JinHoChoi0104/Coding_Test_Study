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
		return parent[u] = find(parent[u]); //��� ����
	}

	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return; //���� �Ҽ��̸� ��ġ�� �ʴ´�
		if (rank[u] > rank[v]) swap(u, v); //v�� ��ũ(����)�� �� Ŀ���� �Ѵ�.
		parent[u] = v; //u�� v�� �ڽ����� �ִ´�.
		if (rank[u] == rank[v]) rank[v]++;
	}
};

int V; //��� ����
vector<pair<int, pair<int, int>>> edges;
int kruskal() {
	int ans = 0, cnt = 0; //�� ������, ���� �� ���� ��
	sort(edges.begin(), edges.end()); // ����ġ�� ũ�⿡ ���� �������� ����

	OptimizedDisjointSet sets(V + 1);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.find(u) == sets.find(v)) continue; //u�� v�� ���� �Ҽ��̸� �н�
		sets.merge(u, v);
		ans += cost;
		cnt++;
		if (cnt == V - 2) //�ʿ��� ������ '��ü ��� - 2��'�̴�.
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