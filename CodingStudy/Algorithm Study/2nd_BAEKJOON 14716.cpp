#include <iostream>
#include <queue>
using namespace std;

int N, M, m[2][8] = { {-1,0,1,-1,1,-1,0,1}, {-1,-1,-1,0,0,1,1,1} };
bool letter[250][250];

void DFS(int x, int y) {
	int tox, toy;
	letter[x][y] = false;
	for (int k = 0; k < 8; k++) {
		tox = x + m[0][k], toy = y + m[1][k];
		if (tox > -1 && tox < N && toy > -1 && toy < M)
			if (letter[tox][toy])
				DFS(tox, toy);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	int num;
	queue<pair<int, int>>q;
	bool isl = false;
	for (int i = 0; i < N; i++) {
		isl = false;
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			if (num == 1) {
				letter[i][j] = true;
				if (!isl) //if it's in same line you don't have to start searching at that point
					q.push(make_pair(i, j)); //save 1's postion to search
				isl = true;
			}
			else
				isl = false;
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		if (letter[q.front().first][q.front().second]) {
			DFS(q.front().first, q.front().second);
			cnt++; //count DFS
		}
		q.pop();
	}
	printf("%d", cnt);
	return 0;
}