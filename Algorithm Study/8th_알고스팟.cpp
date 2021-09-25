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
	queue<pair<int, int>> tmp; //다음 부수기를 위하여!
	while (!crush_q.empty()) {
		int x = crush_q.front().first, y = crush_q.front().second;
		crush_q.pop();

		for (int k = 0; k < 4; k++) {
			int tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M)
				if (!visited[tox][toy] && maze[tox][toy] == 1) { //벽이니?
					visited[tox][toy] = true;
					BFS_q.push({ tox, toy });
					tmp.push({ tox, toy }); 
					//부쉈던 곳을 기억해서 다음 탐색과 부수기에 이용한다
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

	int ans = 0; //지도 사이즈 1*1이면 루프 그만!
	while (N != 1 || M != 1) { //탬색, 뿌셔뿌셔 반복
		if (BFS())
			break;
		ans++;
		if (crush())
			break;
	}
	printf("%d", ans);
	return 0;
}