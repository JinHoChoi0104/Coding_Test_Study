#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char board[20][20];
int N, M;
int m[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
vector<bool>visited(26, false);
int DFS(int x, int y) { //return max number
	int max_visit = 1;
	visited[board[x][y] - 'A'] = true;
	for (int k = 0; k < 4; k++) {
		int tox = x + m[0][k], toy = y + m[1][k];
		if (tox > -1 && tox < N && toy > -1 && toy < M) {
			if (!visited[board[tox][toy]-'A']) { //if not visited alphabet
				max_visit = max(max_visit, DFS(tox, toy)+1);
			}
		}
	}
	visited[board[x][y] - 'A'] = false;
	return  max_visit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	cout << DFS( 0, 0);
	return 0;
}