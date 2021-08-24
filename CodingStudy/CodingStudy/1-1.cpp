#include <iostream>
#include <vector>
using namespace std;
/*
Connected Component (연결 요소)
: The number of connected elements in a graph is the number of subgraphs
Vertices of subgraphs must be connected each others by paths. 
This means if two vertices are in same subgraphs. Must be able to go from one vertex to another.
# GraphTheory #UndirectedGraph
*/
vector<int>arr[1001];
vector<bool>visited(1001);

void DFS(int index) {
	visited[index] = true;
	for (int i = 0; i < arr[index].size(); i++) 
		if (!visited[arr[index][i]])
			DFS(arr[index][i]);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	int N, M, a, b, cnt = 0;

	cin >> N;
	for (cin >> M; M-- > 0;) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
			DFS(i);
		}
	}
	cout << cnt;

	return 0;
}