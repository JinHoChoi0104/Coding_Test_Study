#include<iostream>
#include<queue>

using namespace std;

int N, M;
queue<pair<int, int>> q; // Doyeon's position
char map[601][601];
int m[2][4] = { {-1,1,0,0},{0,0,-1,1} };

void BFS() {
	int x, y, tox, toy, cnt = 0;
	while (!q.empty()) {
		x = q.front().first, y = q.front().second; //from
		q.pop();
		for (int i = 0; i < 4; i++) {
			tox = x + m[0][i], toy = y + m[1][i]; //to
			if (tox > -1 && tox < N && toy > -1 && toy < M) //check range
				if (map[tox][toy] != 'X') { //check wall
					if (map[tox][toy] == 'P')
						cnt++;
					map[tox][toy] = 'X'; //make it wall so never come back again
					q.push(make_pair(tox, toy));
				}
		}
	}
	if (cnt != 0)
		printf("%d", cnt);
	else
		printf("TT");
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 'I') {
				q.push(make_pair(i, j));
				map[i][j] = 'X';
				break;
			}

	BFS();
	return 0;
}