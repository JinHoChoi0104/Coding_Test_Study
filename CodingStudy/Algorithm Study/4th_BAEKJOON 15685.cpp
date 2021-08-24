#include <iostream>
#include <vector>
using namespace std;

/*
px 와 py가 회전축이 되는 점이라고 가정
커브를 하기 위해서는
1. 이동하려는 좌표(x, y)를 원점으로 이동
2. -90회전
3. 1에서 이동했던 거의 반대만큼 이동

(x - px, y - py)({0, 1}, {-1 0}) + (px, py)

tox = -y + py +px, toy = x - px + py

구한 좌표는 벡터뒤로 푸쉬해준다
회전 후 좌표를 구할 때는 원점에서 먼 좌표부터 구해주고 마지막으로 원점을 회전한 좌표를 구한다.
이 원점을 회전한 좌표가 다음 세대의 회전축이 되는 점이기 때문이다.
*/
bool board[101][101];

void curving(vector<pair<int, int>>&arr, int g) {
	int px = arr.back().first, py = arr.back().second;
	int tox, toy, len = arr.size();
	for (int i = len - 2; i >= 0; i--) {
		tox = -arr[i].second + py + px;
		toy = arr[i].first - px + py;
		arr.push_back({ tox, toy });
		board[tox][toy] = true; //그려진 좌표 저장
	}
	if(g > 1)
		curving(arr, --g);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, x, y, d, g, m[2][4] = { {1,0,-1,0},{0,-1,0,1} };
	for (cin >> N; N-- > 0;) {
		cin >> x >> y >> d >> g;
		vector<pair<int, int>>arr;
		arr.push_back({ x, y});
		arr.push_back({ x + m[0][d], y + m[1][d] });
		board[x][y] = true;
		board[x + m[0][d]][y + m[1][d]] = true;
		if(g > 0)
			curving(arr, g);
	}

	int cnt = 0, tox, toy, m2[2][4] = { {0,0,1,1},{0,1,0,1} };
	bool box;
	for (int i = 0; i < 100; i++) { //몇개의 사각형이 있는지 확인
		for (int j = 0; j < 100; j++) {
			box = true;
			for (int k = 0; k < 4; k++) {
				tox = i + m2[0][k], toy = j + m2[1][k];
				if (!board[tox][toy]) {
					box = false;
					break;
				}
			}
			if (box)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}