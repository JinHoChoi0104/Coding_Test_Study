#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sea[20][20];
int N, shark = 2, eat = 0, m[2][4] = { {-1,0,0,1}, {0,-1, 1,0} }; // up left right down
struct pos { int x, y, move; };
queue<pos> q;
vector <vector<int>> visited(20, vector<int>(20));

void clear() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

void BFS() {
	int x, y, tox, toy, total = 0, move = 0;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y;
		move = q.front().move;
		q.pop();

		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < N) {

				if (!visited[tox][toy] && sea[tox][toy] <= shark) {

					if (sea[tox][toy] == 0 || sea[tox][toy] == shark) { //no eating
						visited[tox][toy] = true;
						//cout << tox << toy;
						q.push({ tox, toy, move +1 });
					}
					else { //can eat
						while (!q.empty())
							q.pop();
						cout << tox << ", "<<toy << ":  "<<move + 1 << endl;
						clear(); //restart the journey
						sea[tox][toy] = 0, eat++; //eat
						if (shark == eat) {
							shark++; //get bigger
							eat = 0;
						}
						visited[tox][toy] = true;
						q.push({ tox, toy, 0 });
						total += (move+1);
						break;
					}
				}
			}
		}
	}
	printf("%d", total);
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &sea[i][j]);
			if (sea[i][j] == 9) {
				visited[i][j] = true;
				q.push({ i,j, 0});
				sea[i][j] = 0;
			}
		}
	
	}
	BFS();
	return 0;
}