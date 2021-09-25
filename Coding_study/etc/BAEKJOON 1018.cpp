#include <iostream>
#include <cstring>
using namespace std;

/*
���Ʈ ���� (brute force)
����Ž�� �˰���.��, ������ ��� ����� ���� ����Ѵ�
*/

int main() {
	int n, m;
	cin >> n >> m;

	char** Chess = new char* [n]; //2���� �迭 �����Ҵ�
	for (int i = 0; i < n; i++) {
		Chess[i] = new char[m];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> Chess[i][j];

	int cnt = 0, min = 0;
	for (int i = 0; i < n - 7; i++)
		for (int j = 0; j < m - 7; j++) {
			cnt = 0;
			for (int x = 0; x < 8; x++)
				for (int y = 0; y < 8; y++) {
					if (Chess[i][j] == 'W') {
						if ((x + y) % 2 == 0)
							Chess[i + x][j + y] == 'B' ? cnt++ : NULL;
						else
							Chess[i + x][j + y] == 'W' ? cnt++ : NULL;
					}
					else {
						if ((x + y) % 2 == 0)
							Chess[i + x][j + y] == 'W' ? cnt++ : NULL;
						else
							Chess[i + x][j + y] == 'B' ? cnt++ : NULL;
					}
				}
			cnt > 32 ? cnt = 64 - cnt : NULL;

			if (i == 0 && j == 0)
				min = cnt;
			else
				cnt < min ? min = cnt : NULL;
		}

	cout << min;
	
	return 0;
}