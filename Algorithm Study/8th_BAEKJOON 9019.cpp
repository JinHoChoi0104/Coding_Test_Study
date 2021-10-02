#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

string BFS(int A, int B) {
	queue<pair<int, string>>q;
	q.push({ A,"" });
	int num;
	string cal;
	vector<bool> visited(10000, false); //방문한곳 체크
	visited[A] = true;
	while (!q.empty()) {
		num = q.front().first, cal = q.front().second;
		q.pop();
		int tmp = num;

		// D
		tmp = (2 * num) % 10000;
		if (tmp == B)
			return cal + 'D';
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push({ tmp, cal + 'D' });
		}

		// S
		tmp = num - 1;
		if (tmp == -1) tmp = 9999;
		if (tmp == B)
			return cal + 'S';
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push({ tmp, cal + 'S' });
		}

		// L, R
		int tmp_L = 0, tmp_R = 0;
		int d4 = num % 10;
		num /= 10;
		for (int i = 0; i < 2; i++) { //d2 d3
			tmp = num % 10;
			num /= 10;
			tmp_L += tmp * pow(10, i);
		}
		int d1 = num;
		tmp_R = tmp_L;
		tmp_L *= 100;
		tmp_L += 10 * d4 + d1; //뒤에 d4 d1 붙여준다
		tmp_R += 1000 * d4 + 100 * d1; //앞에 d4 d1 붙여준다
	
		if (tmp_L == B)
			return cal + 'L';
		if (!visited[tmp_L]) {
			visited[tmp_L] = true;
			q.push({ tmp_L, cal + 'L' });
		}
		if (tmp_R == B)
			return cal + 'R';
		if (!visited[tmp_R]) {
			visited[tmp_R] = true;
			q.push({ tmp_R, cal + 'R' });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, A, B;
	for (cin >> T; T-- > 0;) {
		cin >> A >> B;
		cout << BFS(A, B) << "\n";
	}
	return 0;
}