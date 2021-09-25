#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;
int N = 5, M = 5;
char map[5][5];
bool visited[5][5];
struct pos { int x, y, cnt; };
queue<pos>q;
vector<int> answer;
bool BFS(int a, int b) {
	int x, y, tox, toy, cnt;
	int m[2][4] = { {-1,1,0,0},{0,0,-1,1} };
	q.push({ a,b,0 });
	visited[a][b] = true;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();

		for (int k = 0; k < 4; k++) {
			tox = x + m[0][k], toy = y + m[1][k];
			if (tox > -1 && tox < N && toy > -1 && toy < M)
				if (!visited[tox][toy] && map[tox][toy] != 'X') {
					if (map[tox][toy] == 'P')
						return true;

					visited[tox][toy] = true;
					if (cnt != 1) //거리 2인거 체크
						q.push({ tox,toy,cnt + 1 });
				}
		}
	}
	return false;
}
vector<int> solution(vector<vector<string>> places) {

	string str;
	for (int i = 0; i < 5; i++) {
		queue<pos>tmpq; //인원들 저장
		for (int j = 0; j < 5; j++) {
			str = places[i][j];
			for (int k = 0; k < 5; k++) {
				map[j][k] = str[k];
				if (str[k] == 'P') //인원들 저장
					tmpq.push({ j,k,0 });
			}

		}
		bool isDanger = false;
		while (!tmpq.empty()) { //한명씩 BFS
			for (int a = 0; a < 5; a++)
				for (int b = 0; b < 5; b++)
					visited[a][b] = false;

			while (!q.empty())
				q.pop();
			isDanger = BFS(tmpq.front().x, tmpq.front().y);
			tmpq.pop();
			if (isDanger) {
				while (!tmpq.empty())
					tmpq.pop();
				answer.push_back(0);
			}
		}

		if (!isDanger)
			answer.push_back(1);
	}

	return answer;
}