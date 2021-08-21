#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> >edge(100001, vector<int>(0));
int parent[100001];

void BFS() {
	queue <int> q;
	int x;
	q.push(1); //push root first
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < edge[x].size(); i++) { //search all node connected with x
			if (parent[edge[x][i]] == 0) { //if node has no parent yet
				parent[edge[x][i]] = x; // x is node's parent
				q.push(edge[x][i]);
			}
		}
	}
}

int main(void) {
	int N, a, b;
	scanf("%d", &N);

	parent[1] = -1; //node 1 is root
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			edge[a].push_back(b);
			continue;
		}
		if (b == 1) {
			edge[b].push_back(a);
			continue;
		}
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	BFS();
	for (int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
	return 0;
}