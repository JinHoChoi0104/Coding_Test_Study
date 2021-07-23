#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int V, E;
int v[20001];
queue<int>q[20001];

bool DFS(int n, int index) {
	v[n] = index;
	E--;

	index *= -1;
	bool isBiG = true;
	int to;
	while (!q[n].empty() && isBiG) {
		to = q[n].front();
		q[n].pop();
		if (v[to] == index * -1) {
			cout << "NO\n";
			return false;
		}
		isBiG = DFS(to, index);;
	}
	return isBiG;
}

void reset() {
	for (int i = 1; i <= V; i++) {
		v[i] = 0;
		while (!q[i].empty())
			q[i].pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool isBiG;
	int T, a, b, index, to;
	cin >> T;
	while (T--) {
		cin >> V >> E;
		reset();
		isBiG = true;
		
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			q[a].push(b);
			q[b].push(a);
		}
		E *= 2;
		for (int i = 1; i <= V; i++) {
			while (!q[i].empty() && isBiG) {
				to = q[i].front();
				q[i].pop();

				index = v[i] == 1 ? 1 : -1;
				v[i] = index;
				index *= -1;
				if (v[to] == index * -1) {
					cout << "NO\n";
					isBiG = false;
					break;
				}
				isBiG = DFS(to, index);
			}
			if (!isBiG)
				break;
			else if (E == 0) {
				cout << "YES\n";
				break;
			}
		}
	}
	return 0;
}