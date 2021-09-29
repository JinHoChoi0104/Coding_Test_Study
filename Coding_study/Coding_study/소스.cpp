#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct fire_ball {
	int x, y, mass, dis, dir;
};
vector<vector<vector<fire_ball>>> map(50, vector<vector<fire_ball>>(50,vector<fire_ball>(0)));
queue<fire_ball>q; //array of fire ball
int N, m[2][8] = { {-1,-1,0,1,1,1,0,-1},{0,1,1,1,0,-1,-1,-1} };
void move() {
	int x, y, mass, dis, dir;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, mass = q.front().mass;
		dis = q.front().dis, dir = q.front().dir;
		q.pop();
		int tox = x + m[0][dir] * dis, toy = y + m[1][dir] * dis;
		while (tox < 0 || tox > N - 1) {
			if (tox > N - 1)
				tox -= N;
			else if (tox < 0)
				tox += N;
		}
		while (toy < 0 || toy > N - 1) {
			if (toy > N - 1)
				toy -= N;
			else if (toy < 0)
				toy += N;
		}
		map[tox][toy].push_back({tox,toy,mass,dis,dir});
	}
}
void afterMove() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int size = map[i][j].size();
			if (size == 1)
				q.push(map[i][j][0]);
			else if (size > 1) {
				int total_mass=0, total_dis=0, first_dir = map[i][j][0].dir % 2;
				bool isSame = true;
				for (auto it = map[i][j].begin(); it != map[i][j].end(); it++) {
					total_mass += it->mass, total_dis += it->dis;
					if (first_dir != it->dir % 2)
						isSame = false;
				}
				int divided_mass = total_mass / 5, divided_dis = total_dis / size;
				if (divided_mass != 0) {
					int k = 0;
					if (!isSame) k++;
					for (; k < 8; k += 2) {
						q.push({ i, j, divided_mass, divided_dis, k });
					}
				}
			}
			map[i][j].clear();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int M, K;
	cin >> N >> M >> K;
	int a, b, c, d, e;
	for (int i = 0; i < M; i++) { //
		cin >> a >> b >> c >> d >> e;
		q.push({ a-1,b-1,c,d,e });
	}
	while (K-- > 0) {
		move();
		afterMove();
	}
	//get total Mass
	int total_mass = 0;
	while (!q.empty()) {
		total_mass += q.front().mass;
		q.pop();
	}
	cout << total_mass;
	return 0;
}