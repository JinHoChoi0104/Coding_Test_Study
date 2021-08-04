#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<vector<int>> arr(100, vector<int>(100)); // -1 exposed air, 0 inner air, 1 chease
set < pair <int,int>> s;
int N, M, num, max_air = 0, time = 0,  m[2][4] = { { -1, 1, 0, 0} ,{0, 0, -1, 1} };

void melt() {
	set < pair <int, int>> exs(s);
	set < pair <int, int>> ans;
	s.clear();

	int x, y, tox, toy, cnt;
	while (!exs.empty()) {
		auto it = exs.begin();
		pair<int,int> tmp = *it;
		x = tmp.first, y = tmp.second;
		exs.erase(it);
		if (arr[x][y] == -1)
			continue;
		cnt = 0;
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (arr[tox][toy] == -1)
				cnt++;
		}
		if (cnt < 2) {
			s.insert(make_pair(x, y));
			continue;
		}
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (arr[tox][toy] == 1)
				s.insert(make_pair(tox, toy));
		}
		ans.insert({x, y});
	}
	if (!ans.empty())
		time++;
	while (!ans.empty()) {
		auto it = ans.begin();
		pair<int,int> tmp = *it;
		x = tmp.first, y = tmp.second;
		ans.erase(it);
		
		arr[x][y] = -1; //no chease now!
	}
}


void BFS() { // find exposed air
	queue <pair <int, int>> aq; 
	vector<vector<bool>> visited(100, vector<bool>(100, false));
	aq.push({ 0,0 }), arr[0][0] = -1, visited[0][0] = false;
	int x, y, tox, toy;
	while (!aq.empty()) {
		x = aq.front().first, y = aq.front().second;
		aq.pop();
		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M) {
				if (arr[tox][toy] == 1 || visited[tox][toy])
					continue;
				if (arr[tox][toy] == 0) {
					max_air--;
					arr[tox][toy] = -1;
				}
				visited[tox][toy] = true;
				aq.push({ tox, toy });
			}
		}
	}
	
}
int main() {
//	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				max_air++;
		}	

	int tox, toy, cnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				cnt = 0;
				for (int k = 0; k < 4; k++) {
					tox = i + m[0][k], toy = j + m[1][k];
					if (arr[tox][toy] == 0)
						cnt++;
				}
				if (cnt >= 2) //find exposed chease
					s.insert(make_pair(i, j ));
			}
		}
	}
	while (!s.empty()) {
		if(max_air > 0)
			BFS();
		melt();
	}
	printf("%d", time);

	return 0;
}