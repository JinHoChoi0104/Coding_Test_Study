#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 987654321
map<int, int> adj[101]; //to, cost
int N, M;

vector<vector<int>> floydWarshall() {
	//store shortest path on 2nd array
	vector<vector<int>>dist(N + 1, vector<int>(N + 1, INF));
	
	//since the starting city and the destination city are never the same
	for (int i = 1; i <= N; i++)
		dist[i][i] = 0;

	//save adjacent path first
	for (int i = 1; i <= N; i++) 
		for (auto it = adj[i].begin(); it != adj[i].end(); it++)
			dist[i][it->first] = it->second;

	for (int k = 1; k <= N; k++) // k: node passing through
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M;
	int from, to, w;
	while (M-- > 0) { 
		cin >> from >> to >> w;
		if (adj[from][to] == 0 || adj[from][to] > w)
			adj[from][to] = w;
	}

	vector<vector<int>>tmp = floydWarshall();
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			if (tmp[i][j] == INF)
				cout << "0 ";
			else
				cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}