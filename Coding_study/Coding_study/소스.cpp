#include <iostream>
#include <queue>
using namespace std;

vector<vector<bool>> map(50, vector<bool>(50, true)); //true: you can go
bool visited[50][50];
int N, M, target_x, target_y;
int m[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
queue <pair<int, int>> tmp, water, hedge;

void flooding() {
	int x, y, tox, toy;
	while (!water.empty()) {
		x = water.front().first, y = water.front().second;
		water.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M) {
				if (tox == target_x && toy == target_y)
					continue;
				if (map[tox][toy]) {
					map[tox][toy] = false;
					tmp.push({ tox, toy });
				}
			}
		}
	}
	tmp.swap(water);
}
bool BFS() { //return true if arrived
	int x, y, tox, toy;
	while (!hedge.empty()) {
		x = hedge.front().first, y = hedge.front().second;
		hedge.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M) {
				if (map[tox][toy] && !visited[tox][toy]) {
					visited[tox][toy] = true;
					tmp.push({ tox, toy });
					if (tox == target_x && toy == target_y)
						return true;
				}
			}
		}
	}
	tmp.swap(hedge);
	return false;
}

void adventure() {
	int cnt = 0;
	while (1) {
		cnt++;
		flooding();
		if (BFS()) {
			cout << cnt;
			break;
		}
		if (hedge.empty()) {
			cout << "KAKTUS";
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'D')
				target_x = i, target_y = j;
			else if (c == 'S') {
				hedge.push({ i, j });
				visited[i][j] = true;
			}
			else if (c == '.');
			else if (c == 'X')
				map[i][j] = false;
			else {
				map[i][j] = false;
				water.push({ i,j });
			}
		}
	}
	adventure();
	return 0;
}