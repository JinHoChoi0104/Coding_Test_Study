#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
bool visited[100][100];
char war_site[100][100];
queue<pair<int, int>> q;
int N, M;

int BFS(char color) {
	int x, y, tox, toy, cnt = 0;
	int m[2][4] = { {-1,1,0,0},{0,0,-1,1} };
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		cnt++, q.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M) 
				if (!visited[tox][toy] && war_site[tox][toy] == color) {
					visited[tox][toy] = true;
					q.push({ tox, toy });
				}
		}
	}

	return cnt;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf(" %c", &war_site[i][j]);
		
	int W=0, B=0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				q.push({ i, j });
				if (war_site[i][j] == 'W')
					W += pow(BFS('W'), 2);
				else
					B += pow(BFS('B'), 2);
			}
		}
	
	printf("%d %d", W, B);
	return 0;
}