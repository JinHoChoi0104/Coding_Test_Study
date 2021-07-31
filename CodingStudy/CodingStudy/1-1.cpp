#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;
struct tree {
	int x, y;
	bool rot; // true: horizontal, false: vertical คั คำ
	int cnt;
	bool rotated;
};
queue <tree> q;
vector<vector<bool>> map(50, vector<bool>(50, true));
vector<vector<bool>> hvisited(50, vector<bool>(50, false));
vector<vector<bool>> vvisited(50, vector<bool>(50, false));
vector<pair<int, int>> target, start;
int m[2][4] = { {-1,1,0,0} , {0,0,-1,1} };

void BFS() {
	int x, y, tox, toy, turn, cnt;
	int x1, y1, x2, y2;
	bool rot;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y;
		cnt = q.front().cnt + 1;
		rot = q.front().rot;
		if (!q.front().rotated) { // turm
			turn = 0;
			for(int i = -1; i < 2; i++)
				for (int j = -1; j < 2; j++) {
					tox = x + i, toy = y + j;
					if (tox > -1 && tox < N && toy > -1 && toy < N) 
						if (map[tox][toy]) 
							turn++;
				}
			if(turn == 9)
				q.push({ x, y, !rot, cnt, true });
		}

		for (int i = 0; i < 4; i++) { //move
			tox = x + m[0][i], toy = y + m[1][i];
			if (tox > -1 && tox < N && toy > -1 && toy < N) {
				if (map[tox][toy]){
					if (rot) {//hori
						if (!hvisited[tox][toy]) {
							x1 = tox, x2 = tox;
							y1 = toy - 1, y2 = toy + 1;
						}
						else
							continue;
					}
					else {
						if (!vvisited[tox][toy]) {
							x1 = tox - 1, x2 = tox + 1;
							y1 = toy, y2 = toy;
						}
						else
							continue;
					}
					if (x1 > -1 && x1 < N && y1 > -1 && y1 < N)
						if (x2 > -1 && x2 < N && y2 > -1 && y2 < N)
							if (map[x1][y1] && map[x2][y2]) {
								if (target[0].first == x1 && target[0].second == y1) { // check arrival
									if (target[1].first == tox && target[1].second == toy)
										if (target[2].first == x2 && target[2].second == y2) {
											printf("%d ", cnt);
											return;
										}
								}
								q.push({ tox, toy, rot, cnt, false });
								if(rot)
									hvisited[tox][toy] = true;
								else
									vvisited[tox][toy] = true;
							}
					
				}
			}
		}
		q.pop();
	}
	printf("0");
}


int main(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	char c;	//scanf() recognize blank as a single character, so instead of using "%c" should use " %c"
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &c);
			if (c == 'B') 
				start.push_back(make_pair(i, j));
			else if(c=='E')
				target.push_back(make_pair(i, j));		
			else if (c == '1') 
				map[i][j] = false;	
		}
	}

	if (start[0].first == start[1].first) { // horizontal
		q.push({ start[1].first,start[1].second, true, 0, false });
		hvisited[start[1].first][start[1].second] = true;
	}
	else {
		q.push({ start[1].first,start[1].second, false, 0, false });
		vvisited[start[1].first][start[1].second] = true;
	}

	BFS();
	return 0;
}