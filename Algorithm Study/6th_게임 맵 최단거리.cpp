#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int N, M;
bool visited[100][100];
int answer = -1;
struct pos { int x, y, cnt; };
void BFS() {
	queue<pos>q;
	int x, y, tox, toy, cnt;
	int m[2][4] = { {-1,1,0,0},{0,0,-1,1} };
	q.push({ 0,0,1 });
	visited[0][0] = true;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M)
				if (!visited[tox][toy]) {
					if (tox == N - 1 && toy == M - 1) { //도착했으면 stop!
						answer = cnt + 1;
						return;
					}
					visited[tox][toy] = true;
					q.push({ tox,toy,cnt + 1 }); 
				}
		}
	}

}
int solution(vector<vector<int> > maps)
{

	N = maps.size(), M = maps[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 0) //갈 수 없는 곳 그냥 방문했다고 쳐!
				visited[i][j] = true;
			else 
				visited[i][j] = false;
		}
	}
	BFS();
	return answer;
}