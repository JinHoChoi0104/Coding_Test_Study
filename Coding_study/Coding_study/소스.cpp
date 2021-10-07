#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>
using namespace std;
int N, M;
bool isInRange(int& x, int& y) {
	if (x < 0) {
		x = 0;
		return false;
	}
	else if (x > N - 1) {
		x = N - 1;
		return false;
	}
	if (y < 0) {
		y = 0;
		return false;
	}
	else if (y > M - 1) {
		y = M - 1;
		return false;
	}
	return true;
}
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {

	long long answer = 0;
	N = n, M = m;
	int size = 1;
	bool row = true;
	int move[2][4] = { {0,0,-1,1}, {-1,1,0,0} };

	set<pair<int, int>>s;
	s.insert({ x,y });
	for (int i = queries.size() - 1; i >= 0; i--) {
		int dir = queries[i][0], len = queries[i][1];
		if (size == 1) {
			if ((y == 0 && dir == 0) || (y == m - 1 && dir == 1)) {
				row = true;
			}
			if ((x == 0 && dir == 2) || (x == n - 1 && dir == 3)) {
				row = false;

				size += len;
				if (row)
					if (size > M)
						size = M;
				if (!row)
					if (size > N)
						size = N;

				if (x == 0 || y == 0)
					continue;

				x -= move[0][dir] * len, y -= move[1][dir] * len;
				isInRange(x, y);
			}
			else {
				x -= move[0][dir] * len, y -= move[1][dir] * len;
				isInRange(x, y);
			}
		}

		else {
			if (row) {
				if (dir == 2 || dir == 3) {
					x -= move[0][dir] * len, y -= move[1][dir] * len;
					isInRange(x, y);
					continue;
				}
				int y1 = y, y2 = y + size - 1;
				y1 -= move[1][dir] * len;
				y2 -= move[1][dir] * len;
				isInRange(x, y1);
				isInRange(x, y2);
				y = y1;
				size = y2 - y1 + 1;
			}
			if (!row) {
				if (dir == 0 || dir == 1) {
					x -= move[0][dir] * len, y -= move[1][dir] * len;
					isInRange(x, y);
					continue;
				}
				int x1 = x, x2 = x + size - 1;
				x1 -= move[1][dir] * len;
				x2 -= move[1][dir] * len;
				isInRange(x1, y);
				isInRange(x2, y);
				x = x1;
				size = x2 - x1 + 1;
			}
		}

	}

	answer = size;
	//cout << size;
	return answer;
}

int main() {

	vector<vector<int>>arr = { {2,1} ,{0,1},{1,1},{0,1},{2,1} };
	long long aaa = solution(2, 2, 0, 0, arr);

	return 0;
}