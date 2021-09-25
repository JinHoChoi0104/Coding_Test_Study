#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int l1[2] = { -1,-1 }, l2[2], m[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
vector<vector<char>> c(1500, vector<char>(1500));
queue<pair<int, int>> water; //water's position
queue<pair<int, int>> melted; //position of ice, which will be melted
queue<pair<int, int>> q; //swan's routine

void findMelting(vector < vector <bool>>will_melt) {
	int x, y, tox, toy;
	while (!water.empty()) {
		x = water.front().first, y = water.front().second;
		water.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M) 
				if (c[tox][toy] == 'X' && !will_melt[tox][toy]) {
					will_melt[tox][toy] = true;
					melted.push(make_pair(tox, toy));
				}
		}
	}
}

void melting() {
	while (!melted.empty()) {
		c[melted.front().first][melted.front().second] = '.';
		water.push(make_pair(melted.front().first, melted.front().second));
		melted.pop();
	}
}


bool isLinked(vector < vector <bool>>& visited) { //BFS
	int x, y, tox, toy;
	queue <pair<int, int>>tmp;

	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M) { // in range ??
				if (c[tox][toy] != 'X' && !visited[tox][toy]) {
					if (tox == l2[0] && toy == l2[1])  //arrived!
						return true;
					visited[tox][toy] = true;
					q.push(make_pair(tox, toy));
				}
				else if (c[tox][toy] == 'X' && !visited[tox][toy]) {
					visited[tox][toy] = true;
					tmp.push(make_pair(tox, toy));
				}
			}
		}
	}
	q.swap(tmp);
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	vector < vector <bool>>will_melt(N, vector <bool>(M, false));
	vector < vector <bool>>visited(N, vector <bool>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &c[i][j]);
			if (c[i][j] == 'L') {
				if (l1[0] == -1)
					l1[0] = i, l1[1] = j;
				else
					l2[0] = i, l2[1] = j;
				will_melt[i][j] = true;
				water.push(make_pair(i, j));
			}
			else if (c[i][j] == '.') {
				will_melt[i][j] = true;
				water.push(make_pair(i, j));
			}
		}
	}
	
	q.push(make_pair(l1[0], l1[1]));
	visited[l1[0]][l1[1]] = true;
	
	int cnt = 0;
	while (1) {
		cnt++;
		findMelting(will_melt);
		melting();
		if (isLinked(visited))
			break;
	}
	printf("%d", cnt);
}