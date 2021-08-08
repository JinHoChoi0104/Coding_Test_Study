#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
vector<int> graph2[10001];
int arr[10001];
bool visited[10001];
bool visited2[10001];
bool done[10001];

int N, M;
int DFS(int to) {
	int com = 1, num;
	visited[to] = true;
	done[to] = true;
	for (int i = 0; i < graph[to].size(); i++) {
		num = graph[to][i];
		if (!visited[num])
			com += DFS(num);
	}
	return com;
}
void reverseDFS(int to, int val) {
	int com = 1, num;
	visited2[to] = true, arr[to] = val;
	for (int i = 0; i < graph2[to].size(); i++) {
		num = graph2[to][i];
		if (visited[num] && !visited2[num])
			reverseDFS(num, val);
	}
}
void reset() {
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}
int main() {
	scanf("%d %d", &N, &M);
	int from, to, max_com = 0;
	while(M--) {
		scanf("%d %d", &from, &to);
		graph[to].push_back(from);
		graph2[from].push_back(to);
	}

	for (int i = 1; i <= N; i++) {
		if (!done[i]) {
			reset();
			arr[i] = DFS(i);
			reverseDFS(i, arr[i]);
			max_com = max(max_com, arr[i]);
		}
	}
	for (int i = 1; i <= N; i++)
		if (arr[i] == max_com)
			printf("%d ", i);
	return 0;
}