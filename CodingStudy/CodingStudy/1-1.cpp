#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isClean[50][50];
bool wall[50][50];
int N, M, cnt = 0, m[2][4] = { {-1,0,1,0 }, {0,1,0,-1} };//up, right, down, left

void cleaning(int x, int y, int d) {
	if (!isClean[x][y]) { // 1
		isClean[x][y] = true;
		cnt++;
	}
	int tox, toy;
	for (int k = 1; k <= 4; k++) { //2
		d--;
		if (d == -1) d = 3;
		tox = x + m[0][d], toy = y + m[1][d];
		if (!wall[tox][toy] && !isClean[tox][toy]) { //2-a
			cleaning(tox, toy, d);
			return;
		}
	}
	tox = x - m[0][d], toy = y - m[1][d];
	if (!wall[tox][toy]) //2-c
		cleaning(tox, toy, d);
} //2-d
int main() {
	//freopen("input.txt", "r", stdin);
	int r, c, d, num;
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
//	scanf("%d %d %d", &r, &c, &d);
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			wall[i][j] = num;
		}
	cleaning(r, c, d);
	printf("%d", cnt);
	return 0;
}