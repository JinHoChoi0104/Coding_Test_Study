#include <iostream>
#include <queue>
using namespace std;

int R, C, ans = 1, m[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
bool maze[1000][1000];
queue<pair<int, int>> fire, jihoon; //���� ��ġ, �������� ��ġ
bool is_arrived = false; //�����ߴ�?
vector<vector<bool>>visited(1000, vector<bool>(1000, false)); //�湮 ����
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
					tmp.push({ tox, toy }); //���� �� �¿� ��
					maze[tox][toy] = false; //�� �¿� ������
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
			if(tox > -1 && tox < R && toy > -1 && toy < C) //���� ���̰�
				if (!visited[tox][toy] && maze[tox][toy]) { //�湮 ���� ����, �� Ÿ�� �ʾҰ� ���� �ƴϴ�
					if (tox == 0 || tox == R - 1 || toy == 0 || toy == C - 1) { //���� ���� Ȯ��
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

	if (is_arrived) //�̹� ����
		cout << 1;
	else
		burning();
	return 0;
}