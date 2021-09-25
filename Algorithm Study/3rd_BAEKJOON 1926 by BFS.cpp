#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, m[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
vector<vector<bool>> pic(500, vector<bool>(500));
struct pos { int x, y; };

int BFS(int fx, int fy) {
	int x, y, tox, toy, cnt = 0; //방문한 노드의 수 저장
	queue<pos>q;

	q.push({ fx, fy });
	pic[fx][fy] = false;
	while (!q.empty()) {
		cnt++; 
		x = q.front().x, y = q.front().y;
		q.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy  > -1 && toy < M) // 범위 안인지
				if (pic[tox][toy]) { //방문 한적 있는지
					q.push({ tox, toy });
					pic[tox][toy] = false;
				}
		}
	}
	return cnt;
}


int main(void) {
	int num;
	scanf("%d %d", &N, &M);
	queue<pos> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			if (num == 1) {
				pic[i][j] = true;
				q.push({ i, j }); // 그림 좌표 저장
			}
		}
	}
	int x = 0, y = 0, cnt = 0, big_pic = 0; //몇개 그림, 제일 큰 그림
	while (!q.empty()) {
		x = q.front().x, y = q.front().y;
		q.pop();
		if (pic[x][y]) {
			big_pic = max(big_pic, BFS(x, y));
			cnt++;
		}	
	}

	printf("%d\n%d", cnt, big_pic);
	return 0;
}