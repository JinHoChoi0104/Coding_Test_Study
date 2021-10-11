#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct NaiveDisjointSet {
	vector<int>parent;
	NaiveDisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	//return root of set which includes u
	int find(int u) const {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}
	//union set including u, with set including v
	void merge(int u, int v) {
		u = find(u), v = find(v);
		//do not union if u and v are included in same set
		if (u == v)return;
		parent[u] = v;
	}
};

struct OptimizedDisjointSet {
	vector<int> parent, rank;
	//rank: store heigth of tree, if node is root of it's tree
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	//return root of set which includes u
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]); //Path Compression (경로 압축) Optimization
	}
	//union set including u, with set including v
	void merge(int u, int v) {
		u = find(u), v = find(v);
		//do not union if u and v are included in same set
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		//make rank[v] more higer than rank[u]
		//then make u to v's child
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};

const int MAX_V = 10000;
int V; // number of vertex
//Graph's linked list. adj[0] = (vertex 0's adjacent vertex, weight to get there)
vector<pair<int, double>> adj[MAX_V];

double kruskal(vector<pair<int, int>>& selected) {
	double ret = 0;
	selected.clear();
	vector<pair<double, pair<int, int>>> edges;
	for (int u = 0; u < V; u++)
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			double cost = adj[u][i].second;
		//	cout << cost << endl;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	//sort edges by it's weight
	sort(edges.begin(), edges.end());
	//
	OptimizedDisjointSet sets(V);
	for (int i = 0; i < edges.size(); i++) {
		double cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		//if u and v are already in same set, then ignore
		if (sets.find(u) == sets.find(v)) continue;
		//if not union them
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	//	cout << ret << endl;
	}
	return ret;
}

vector<pair<double, double>> pos;
double doublePow(double num) {
	return num * num;
}
double getDis(int u, int v) {
	double dx = doublePow(pos[u].first - pos[v].first);
	double dy = doublePow(pos[u].second - pos[v].second);
	return sqrt(dx + dy);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> V;
	double a, b;
	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		pos.push_back({ a,b });
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j)
				continue;
			double dis = getDis(i, j);
			adj[i].push_back({ j, dis});
			adj[j].push_back({ i, dis});
		}

	}
	vector<pair<int, int>> selected;
	cout << fixed;
	cout.precision(2);
	cout << kruskal(selected);
	return 0;
}