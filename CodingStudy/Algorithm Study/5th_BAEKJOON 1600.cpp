#include <iostream>
#include <queue>
using namespace std;

int W, H, K, m[2][12] = { {1,-1,0,0, 2,1,2, 1, -1, -2, -2, -1}, {0,0,1,-1,1,2, -1, -2, 2, 1, -1, -2} };
bool visited[32][200][200]; //������ ��� �ؼ� �湮�ߴ°�
struct monkey { int x, y, jump, cnt; }; //��ġ, ���� �� Ƚ��, ������ �ð�
queue<monkey>q;

void BFS() {
	int x, y, jump, cnt, tox, toy;
	while (!q.empty()) {
		monkey tmp = q.front();
		q.pop();

		for (int k = 0; k < 12; k++) {
			if (k >= 4 && tmp.jump == K)
				break;
			tox = tmp.x + m[0][k], toy = tmp.y + m[1][k];
			if (tox > -1 && tox < H && toy > -1 && toy < W) {	
				if (!visited[tmp.jump][tox][toy] && k < 4) { // ���� �� �ϰ� ������	
					q.push({ tox, toy, tmp.jump, tmp.cnt + 1 });
					visited[tmp.jump][tox][toy] = true;
					if (tox == H - 1 && toy == W - 1) {
						printf("%d", tmp.cnt + 1);
						return;
					}
				}
				else if (!visited[tmp.jump + 1][tox][toy] && k >= 4) { // ���� �ؼ� ������
					q.push({ tox, toy, tmp.jump + 1, tmp.cnt + 1 });
					visited[tmp.jump + 1][tox][toy] = true;
					if (tox == H - 1 && toy == W - 1) {
						printf("%d", tmp.cnt + 1);
						return;
					}
				}
			}
		}
	}
	printf("-1");
}

int main() {
	int num;

	scanf("%d %d %d", &K, &W, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &num);
			if (num == 1) { //��ֹ��� �湮���� �ִٰ� ġ��
				for (int k = 0; k <= K; k++) 
					visited[k][i][j] = true;
			}
		}
	}
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;
	if (H==1 && W == 1) { //����� = ������
		printf("%d", 0);
		return 0;
	}
	BFS();
	return 0;
}