/*
copyright: "프로그래밍대회에서 배우는 알고리즘 문제해결전략"
studing Unionfind, DisjointSet
*/
#include <iostream>
#include <vector>
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
int main() {
	NaiveDisjointSet sets(5);
	for (int i = 0; i < 5; i++)
		cout << sets.parent[i];
	return 0;
}