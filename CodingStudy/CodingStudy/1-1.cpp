#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct line {
	int to, len;
};
vector <vector<line>> edge(100001, vector<line>(0));
vector<bool> visited(100001);
int N;
void clear() {
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}
int BFS(int index) {
	clear();
	queue<line> q;
	q.push({ index, 0 });
	visited[index] = true;
	int from, sum ,index2, max_di =0;
	bool end;
	while (!q.empty()) {
		from = q.front().to, sum = q.front().len;
		q.pop();
		end = true;
		for (int i = 0; i < edge[from].size(); i++) {
			if (!visited[edge[from][i].to]) { //not visited yet
				visited[edge[from][i].to] = true;
				q.push({ edge[from][i].to, sum + edge[from][i].len });
				end = false;
			}
		}
		if (end) { // if no where to go
			if (sum > max_di) {
				index2 = from;
				max_di = sum;
			}
		}
	}
	clear();
	q.push({ index2, 0 });
	visited[index2] = true;
	while (!q.empty()) {
		from = q.front().to, sum = q.front().len;
		q.pop();
		end = true;
		for (int i = 0; i < edge[from].size(); i++) {
			if (!visited[edge[from][i].to]) { //not visited yet
				visited[edge[from][i].to] = true;
				q.push({ edge[from][i].to, sum + edge[from][i].len });
				end = false;
			}
		}
		if (end) // if no where to go
			max_di = max (max_di, sum);
	}
	return max_di;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int from, to, len, max_len = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		while (to != -1) {
			cin >> len;
			edge[from].push_back({ to, len });
			cin >> to;
		}
	}

	cout << BFS(1);
	
	return 0;
}