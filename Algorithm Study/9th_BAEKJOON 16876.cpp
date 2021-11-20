#include <iostream>
#include <queue>
using namespace std;

int R, C, ans = 1, m[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
bool maze[1000][1000];
queue<pair<int, int>> fire, jihoon; //불의 위치, 지훈이의 위치
bool is_arrived = false; //도착했니?
vector<vector<bool>>visited(1000, vector<bool>(1000, false)); //방문 여부
void burning();
void BFS();

void burning() {
	int x, y;
	queue<pair<int, int>> tmp;
	while (!fire.empty()) {
		x = fire.front().first, y = fire.front().second;
		fire.pop();
		for (int k = 0; k < 4; k++) {
			int tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < R && toy > -1 && toy < C) {
				if (maze[tox][toy]) {
					tmp.push({ tox, toy }); //다음 불 태울 곳
					maze[tox][toy] = false; //불 태워 버린다
				}
			}
		}
	}
	
	tmp.swap(fire);
	BFS();
}
void BFS() {
	int x, y;
	ans++;
	queue<pair<int, int>> tmp;
	if (jihoon.empty()) {
		cout << "IMPOSSIBLE";
		return;
	}
	while (!jihoon.empty()) {
		x = jihoon.front().first, y = jihoon.front().second;
		jihoon.pop();
		for (int k = 0; k < 4; k++) {
			int tox = x + m[0][k], toy = y + m[1][k];
			if(tox > -1 && tox < R && toy > -1 && toy < C) //범위 안이고
				if (!visited[tox][toy] && maze[tox][toy]) { //방문 한적 없고, 불 타지 않았고 벽이 아니다
					if (tox == 0 || tox == R - 1 || toy == 0 || toy == C - 1) { //도착 여부 확인
						is_arrived = true;
						break;
					}
					tmp.push({ tox, toy });
					visited[tox][toy] = true;
				}
		}
	}

	if (is_arrived) 
		cout << ans;
	
	else {
		tmp.swap(jihoon);
		burning();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> R >> C;
	char ch;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> ch;
			if (ch == 'F')
				fire.push({ i, j });
			else if (ch == 'J') {
				jihoon.push({ i, j });
				maze[i][j] = true;
				if (i == 0 || i == R - 1 || j == 0 || j == C - 1)
					is_arrived = true;
				visited[i][j] = true;
			}
			else if( ch=='.')
				maze[i][j] = true;
		}
	}

	if (is_arrived) //이미 도착
		cout << 1;
	else
		burning();
	return 0;
}