#include <iostream>
using namespace std;

int N, ground[11][11], a[11][11], b[11][11]; //size, ground's status, A[][], dead tree
int m[2][8] = { {-1,-1,-1,0,0,1,1,1}, {-1,0,1,-1,1,-1,0,1} };
int forest[11][11][1012], oldest[11][11];
void spring() {
	int grown, prev, d, index = 0; //how many tree will be grown, how many tree has been grown from front
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prev = 0, index = 0;
			for (int p = 1; p <= oldest[i][j] + 2; p++) { //age
				int& ret = forest[i][j][p];

				if (ret * p <= ground[i][j])  //no tree or enough soil
					grown = ret;
				else { //dead
					grown = ground[i][j] / p;
					d = p / 2; // since you throw away decimal, should calculate as if only one tree
					b[i][j] += (ret - grown) * d;
				}

				ret = prev,	prev = grown;
				ground[i][j] -= p * grown;
				if (ret > 0)
					index = p;
			}
			oldest[i][j] = index;
		}
	}
}
void summer() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			ground[i][j] += b[i][j];
			b[i][j] = 0;
		}
}
void fall() {
	int tox, toy;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int p = 5; p <= oldest[i][j]; p+=5) {
				int& ret = forest[i][j][p];
				if (ret > 0) {
					for (int k = 0; k < 8; k++) {
						tox = i + m[0][k], toy = j + m[1][k];
						if (tox > 0 && tox <= N && toy > 0 && toy <= N) 
							forest[tox][toy][1] += ret;
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ground[i][j] += a[i][j];
}
int main() {
	int M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[i][j]);
			ground[i][j] = 5;
		}
	}
	int x, y, z; // position, age
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		forest[x][y][z]++;
		oldest[x][y] = z;
	}

	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int p = 1; p <= oldest[i][j] + 1; p++)
				cnt += forest[i][j][p];

	printf("%d", cnt);
	return 0;
}