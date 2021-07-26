#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M, max_air, min_virus = 64; //size of map
int m[2][4] = { {-1, 0 ,1, 0}, {0, 1, 0, -1} }; // up, right, down, left

vector<vector<int>> map(8, vector<int>(8)); //0: air, 1: wall, 2: virus
vector<pair<int, int>> air;

struct virus { int x, y; }; // store original virus's position
queue <virus> virusq;

vector<vector<int>> tmp_map; //temporary container for BFS
queue <virus> tmp_q;

void BFS() {
	tmp_map = map;
	tmp_q = virusq;
	int x, y, tox, toy, cnt = 0;
	while (!tmp_q.empty() && cnt <= min_virus && cnt != max_air) {//if virus visit more than before, or polluted all air then stop!!!
		x = tmp_q.front().x, y = tmp_q.front().y;
		tmp_q.pop();
		
		for (int i = 0; i < 4; i++) {
			tox = x + m[0][i], toy = y + m[1][i];
			if (tox > -1 && tox < N && toy > -1 && toy < M) //check range
				if (tmp_map[tox][toy] == 0) { //check whether it is air
					tmp_q.push({ tox,toy });
					tmp_map[tox][toy] = 2; //visit
					cnt++;
				}
		}
	}

	min_virus = min(min_virus, cnt);
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			map[i][j] = num;
			if (num == 0) 
				air.push_back(make_pair(i, j));
			else if (num == 2)
				virusq.push({ i,j });
		}
	}

	max_air = air.size();

	for (int i = 0; i < max_air - 2; i++) {
		map[air[i].first][air[i].second] = 1;
		for (int j = i + 1; j < max_air - 1; j++) {
			map[air[j].first][air[j].second] = 1;
			for (int k = j + 1; k < max_air; k++) {
				map[air[k].first][air[k].second] = 1;
				BFS();
				map[air[k].first][air[k].second] = 0;
			}
			map[air[j].first][air[j].second] = 0;
		}
		map[air[i].first][air[i].second] = 0;
		
	}

	printf("%d", max_air - min_virus - 3);
	return 0;
}