// BAEKJOON 1260

#include <iostream>
using namespace std;

#include <queue>

void dfs(int from, int *arr[], bool *visited, int N) { //used recursion to implement dfs
	visited[from] = true;
	cout << from << " ";
	for (int i = 1; i < N + 1; i++) {
		if (arr[from][i] != 0 && visited[i] == false)
			dfs(i, arr, visited, N);
	}
}

queue <int> map;
void bfs(int from, int* arr[], bool* visited, int N) {
	cout << from << " ";
	visited[from] = true;
	
	for (int i = 1; i < N + 1; i++) {
		if (arr[from][i] != 0 && visited[i] == false) {
			map.push(i);
			visited[i] = true;
		}
	}
	
	if (!map.empty()) { //check if there is no places to visit
		int next = map.front();
		map.pop();
		bfs(next, arr, visited, N);
	}
}

int main() {
	int N, M, V; //nod, line, starting nod
	cin >> N >> M >> V;

	bool *visited = new bool[N+1];
	int** arr = (int**)malloc(sizeof(int*) * (N + 1));


	for (int i = 0; i < N + 1; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (N + 1));
		visited[i+1] = false;
		for (int j = 0; j < N + 1; j++)
			arr[i][j] = 0;
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(V, arr, visited, N);
	cout << endl;

	for (int i = 0; i < N + 1; i++) 
		visited[i + 1] = false;
	
	bfs(V, arr, visited, N);
}