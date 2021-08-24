#include <iostream>
#include <vector>
using namespace std;

/*
px �� py�� ȸ������ �Ǵ� ���̶�� ����
Ŀ�긦 �ϱ� ���ؼ���
1. �̵��Ϸ��� ��ǥ(x, y)�� �������� �̵�
2. -90ȸ��
3. 1���� �̵��ߴ� ���� �ݴ븸ŭ �̵�

(x - px, y - py)({0, 1}, {-1 0}) + (px, py)

tox = -y + py +px, toy = x - px + py

���� ��ǥ�� ���͵ڷ� Ǫ�����ش�
ȸ�� �� ��ǥ�� ���� ���� �������� �� ��ǥ���� �����ְ� ���������� ������ ȸ���� ��ǥ�� ���Ѵ�.
�� ������ ȸ���� ��ǥ�� ���� ������ ȸ������ �Ǵ� ���̱� �����̴�.
*/
bool board[101][101];

void curving(vector<pair<int, int>>&arr, int g) {
	int px = arr.back().first, py = arr.back().second;
	int tox, toy, len = arr.size();
	for (int i = len - 2; i >= 0; i--) {
		tox = -arr[i].second + py + px;
		toy = arr[i].first - px + py;
		arr.push_back({ tox, toy });
		board[tox][toy] = true; //�׷��� ��ǥ ����
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
	for (int i = 0; i < 100; i++) { //��� �簢���� �ִ��� Ȯ��
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