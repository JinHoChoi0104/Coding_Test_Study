#include <iostream>
#include <algorithm>
using namespace std;

int board[500][500];
int N, M, max_sum = 0, m[2][4] = { {-1,1,0,0} , {0,0,-1,1} };

void DFS(int x, int y, int cnt, int dir, int sum) {
	int tox, toy, add = 0, add2 = 0;
	sum += board[x][y];
	
	if (dir == 1) dir = 0;
	else if (dir == 0) dir = 1;
	else if (dir == 2) dir = 3; 
	else if (dir == 3) dir = 2; //not going back

	for (int k = 0; k < 4; k++) {
		if (k == dir)
			continue;
		tox = x + m[0][k], toy = y + m[1][k];
		if (tox > -1 && tox <N && toy > -1 && toy < M) {
			if (cnt != 3) {
				DFS(tox, toy, cnt + 1, k, sum);
				if (cnt == 2) {
					if (board[tox][toy] > add && board[tox][toy] > add2) {
						add2 = add;
						add = board[tox][toy];
					}
					else if (board[tox][toy] > add2)
						add2 = board[tox][toy];
				}
			}
			else 
				add = max(add, board[tox][toy]);
		}
	}
	if (cnt == 2) {
		sum = sum + add + add2;
		max_sum = max(max_sum, sum);
	}
	else if (cnt == 3) {
		sum += add;
		max_sum = max(max_sum, sum);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &board[i][j]);
	int ans = 0, sum = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			DFS(i, j, 1, 4, 0);

	printf("%d", max_sum);
	return 0;
}