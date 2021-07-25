#include<iostream>
#include<vector>

using namespace std;

vector < vector<bool> > video(64, vector<bool>(64, false));

void QuadTree(int x, int y, int size) {
	bool color = video[x][y];
	if (size != 1) {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (color != video[i][j]) {
					printf("(");
					QuadTree(x, y, size / 2);
					QuadTree(x, y + size / 2, size / 2);
					QuadTree(x + size / 2, y, size / 2);
					QuadTree(x + size / 2, y + size / 2, size / 2);
					printf(")");
					return;
				}
			}
		}
	}

	if (color)
		printf("1");
	else
		printf("0");
}

int main(void) {
	int N, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &num);
			if (num == 1)
				video[i][j] = true;
		}
	}
	
	QuadTree(0, 0, N);
	return 0;
}