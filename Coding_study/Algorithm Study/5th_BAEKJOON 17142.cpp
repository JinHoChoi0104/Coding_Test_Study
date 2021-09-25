#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int N, M, max_p = 0, pollutted, lab[50][50];
bool visited[50][50];
struct tmpV { int x, y, cnt; };
queue<tmpV>q;

int BFS() {
	int x, y, cnt, tox, toy, m[2][4] = { {-1,1,0,0},{0,0,-1,1} };
	pollutted = 0;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < N)
				if (!visited[tox][toy] && lab[tox][toy] != 1) { //방문 한 적 없고, 벽이 아니면
					q.push({ tox,toy,cnt + 1 });
					visited[tox][toy] = true;
					if (lab[tox][toy] == 0) //빈 공기일 경우 카운트
						pollutted++;
				}
		}
		if (max_p == pollutted) //모든 빈 공기가 오염 됐으면 걸린 초 수 반환
			return cnt + 1;
	}
	return 3000; //모든 빈 공기를 오염 못 시킨 경우
}
int main() {
	scanf("%d %d", &N, &M);
	vector<pair<int, int>>virus;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int& ret = lab[i][j];
			scanf("%d", &ret);
			if (ret == 2)
				virus.push_back({ i,j });
			if (ret == 0)
				max_p++; //전체 빈 공기의 수
		}
	if (max_p == 0) { //이미 오염이 다 돼 있다면
		printf("0");
		return 0;
	}

	int ans = 3000, V = virus.size();
	vector<int> order(V, 0);
	for (int i = V - 1; i >= V - M; i--)
		order[i] = 1;
	do {
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < V; i++) {
			if (order[i] == 1) {
				q.push({ virus[i].first, virus[i].second, 0 });
				visited[virus[i].first][virus[i].second] = true;
			}
		}
		ans = min(ans, BFS());
		while (!q.empty())
			q.pop();
	} while (next_permutation(order.begin(), order.end())); //순열 함수를 이용해 조합 구현

	if (ans != 3000)
		printf("%d", ans);
	else
		printf("-1");
	return 0;
}