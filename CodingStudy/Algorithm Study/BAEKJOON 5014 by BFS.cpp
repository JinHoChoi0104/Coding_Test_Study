#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//BFS
int main() {
	int floor, pos, to, m[2], u, d, cnt = 0, topos;
	vector<bool> visited;
	
	scanf("%d %d %d %d %d", &floor, &pos, &to, &u, &d);

	for (int i = 0; i <= floor; i++)
		visited.push_back(false);

	m[0] = u, m[1] = -d;

	queue<pair<int,int>>q; //pos,cnt
	q.push(make_pair(pos, cnt));
	visited[pos] = true;
	while (!q.empty()) {
		pos = q.front().first;
		cnt = q.front().second;
		q.pop();
		
		if (pos == to) {
			printf("%d", cnt);
			return 0;
		}
		for (int i = 0; i < 2; i++) {
			topos = pos + m[i];
			if (topos <= floor && topos >= 1) {
				if (!visited[topos]) {
					q.push(make_pair(topos, cnt + 1));
					visited[topos] = true;
				}
			}
		}
	}
	
	printf("use the stairs");

	return 0;
}