#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int sea[20][20];
int N, shark = 2, eat = 0, m[2][4] = { {-1,0,0,1}, {0,-1, 1,0} }; // up left right down
struct pos { int x, y, move; };
queue<pos> q;
vector <vector<bool>> visited(20, vector<bool>(20));
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}
void clear() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

void BFS() {
	int x, y, tox, toy, total = 0, move = 0;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y;
		move = q.front().move + 1;
		q.pop();

		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < N) {
				if (!visited[tox][toy] && sea[tox][toy] <= shark) {
					if (sea[tox][toy] == 0 || sea[tox][toy] == shark) { //no eating
						visited[tox][toy] = true;
						q.push({ tox, toy, move });
					}
					else { //can eat
						vector<pair<int, int>> arr;
						int index = move;
						arr.push_back(make_pair(tox, toy));
						visited[tox][toy] = true;
						while (!q.empty()) { //find all fish that can be eaten in same distance
							x = q.front().x, y = q.front().y;
							move = q.front().move;
							if (move == index) break;
							q.pop();
							for (int i = 0; i < 4; i++) {
								tox = x + m[0][i], toy = y + m[1][i];
								if (tox > -1 && tox < N && toy > -1 && toy < N) 
									if (!visited[tox][toy] && sea[tox][toy] < shark && sea[tox][toy] > 0) 
										arr.push_back(make_pair(tox, toy));							
							}
						}
						while (!q.empty()) q.pop();
						
						sort(arr.begin(), arr.end(), compare);
						tox = arr[0].first, toy = arr[0].second;
						clear(); //restart the journey
						sea[tox][toy] = 0, eat++; //eat
						if (shark == eat) {
							shark++; //get bigger
							eat = 0;
						}
						visited[tox][toy] = true;
						q.push({ tox, toy, 0 });
						total += (index);
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

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			scanf("%d", &sea[i][j]);
			if (sea[i][j] == 9) {
				visited[i][j] = true;
				q.push({ i,j, 0 });
				sea[i][j] = 0;
			}
		}

	BFS();
	return 0;
}