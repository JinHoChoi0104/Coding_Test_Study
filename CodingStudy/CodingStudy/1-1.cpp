// BAEKJOON 18404
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct knight {int x, y, n;};
struct enemy {int x, y, n;};
int N, M, cnt = 0;
int board[501][501]; //no 0
// -1 have been before, 1 never have been before , 2 enemy
//vector <pair<int, int>> enemy; //[x][y], x is vertical
vector <enemy> enemy_arr;
queue <knight> knight_arr;

void killEnemy(int x, int y, int n) {
	for (int i = 0; i < M; i++) {
		if (enemy_arr[i].x == x && enemy_arr[i].y == y) {
			cnt++;
			enemy_arr[i].n = n;
			break;
		}
	}
}
int K1[] = { -2,-2,-1,-1,1,1,2,2 }, K2[] = { -1,1,-2,2,-2,2,-1,1 };
void moveKnight() { //doing bfs
	int x = 0, y = 0, n = 0;
	while (!knight_arr.empty()) {
		x = knight_arr.front().x;
		y = knight_arr.front().y;	
		n = knight_arr.front().n;
		knight_arr.pop();

		if (x > 0 && x < N + 1 && y > 0 && y < N + 1) { // is in range?
			if (board[x][y] > 0) { //is never have been before
				if (board[x][y] == 2) 
					killEnemy(x, y, n);

				board[x][y] = -1;
				for(int i = 0; i < 8; i++)
					knight_arr.push(knight{ x + K1[i], y + K2[i], n + 1});
			}
		}
		if (cnt == M) 
			break;
	}
}

int main(void) {
	int x = 0, y = 0;
	cin >> N >> M >> x >> y;
	knight_arr.push(knight{ x, y, 0 });

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++)
			board[i][j] = 1;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		board[x][y] = 2;
		enemy_arr.push_back({ x,y,0 });
	}

	moveKnight();

	for (int i = 0; i < M; i++)
		printf("%d ",enemy_arr[i].n);
	return 0;
}