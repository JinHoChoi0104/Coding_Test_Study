#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, m[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
int maze[100][100];
bool visited[100][100];

queue<pair<int, int>>BFS_q; //queue for journey
queue<pair<int, int>>crush_q; //queue for crushing wall

bool BFS() {
	while (!BFS_q.empty()) {
		int x = BFS_q.front().first, y = BFS_q.front().second;
		BFS_q.pop();
	
		for (int k = 0; k < 4; k++) {
			int tox = x + m[0][k], toy = y + m[1][k];
			if(tox > -1 && tox < N && toy > -1 && toy < M)
				if (!visited[tox][toy] && maze[tox][toy] == 0)	{
					visited[tox][toy] = true;
					BFS_q.push({ tox, toy });
					crush_q.push({ tox, toy });
					if (tox == N - 1 && toy == M - 1)
						return true;
				}
		}
	}
	return false;
}
bool crush() {
	queue<pair<int, int>> tmp; //this is for next crush
	while (!crush_q.empty()) {
		int x = crush_q.front().first, y = crush_q.front().second;
		crush_q.pop();

		for (int k = 0; k < 4; k++) {
			int tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M)
				if (!visited[tox][toy] && maze[tox][toy] == 1) { //check if it is wall
					visited[tox][toy] = true;
					BFS_q.push({ tox, toy });
					tmp.push({ tox, toy }); 
					//Remember position where you just have crushed
					//Because you should start next jurney and crush next wall at there
					if (tox == N - 1 && toy == M - 1)
						return true;
				}
		}
	}
	tmp.swap(crush_q);
	return false;
}
int main() {
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			scanf("%1d", &maze[i][j]);
	
	vector<vector<int>>visited(N, vector<int>(M, false));
	BFS_q.push({ 0, 0 });
	visited[0][0] = true;
	crush_q.push({ 0, 0 });
	//Initialize

	int ans = 0; //If map size if 1*1 don't implement loop
	while (N != 1 || M != 1) { //Repeat journey and crush until you meat arrival point
		if (BFS())
			break;
		ans++;
		if (crush())
			break;
	}
	printf("%d", ans);
	return 0;
}