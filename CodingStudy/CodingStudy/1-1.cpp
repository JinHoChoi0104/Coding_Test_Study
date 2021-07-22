#include<iostream>
#include<queue>

using namespace std;

struct night {	int x, y, cnt, from;};
bool board[300][300]; //true: never been before so can go
int L; //board size
int m[2][8] = { { -1,-2,-2,-1,1,2,2,1 } ,{ -2,-1,1,2,2,1,-1,-2 } };
void clearBoard() {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			board[i][j] = true;
}

int BFS(int fromX, int fromY, int toX, int toY) {
	queue <night> q;
	q.push({ fromX, fromY, 0, 8 });
	int x, y, cnt, from;
	while (1) {
		x = q.front().x;
		y = q.front().y;
		from = q.front().from;
		from = from >= 4 ? from - 4 : from + 4;
		for (int i = 0; i < 8; i++) {
			if (from != 8) {
				x = q.front().x + m[0][i];
				y = q.front().y + m[1][i];

				if (x > -1 && x < L && y > -1 && y < L) { //in range?
					if (board[x][y]) { //never have been?
						cnt = q.front().cnt + 1;
						if (x == toX && y == toY) 
							return cnt;

						board[x][y] = false;
						q.push({ x, y, cnt, i });
					}
				}
			}
		}
		q.pop();
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	int fromX, fromY, toX, toY;
	while (T--) {
		scanf("%d %d %d %d %d", &L, &fromX, &fromY, &toX, &toY);
		if (fromX == toX && fromY == toY)
			cout << "0\n";
		else {
			clearBoard();
			cout << BFS(fromX, fromY, toX, toY) << "\n";
		}
	}
	return 0;
}