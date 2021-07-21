#include<iostream>
#include<queue>
using namespace std;

int m1[6] = { -1, 1, 0, 0 , 0 ,0}, m2[6] = { 0, 0, -1, 1, 0 , 0}, m3[6] = { 0, 0, 0, 0, -1, 1 };
struct pos {
	int pos_x, pos_y, pos_z, pos_from, pos_cnt;
};
queue <pos> arr;
int M, N, H, raw = 0, ripen=0;
int board[100][100][100]; // x y z
void DFS() {
	int x, y, z, from, cnt;
	while (!arr.empty()) {
		x = arr.front().pos_x;
		y = arr.front().pos_y;
		z = arr.front().pos_z;
		if (x > -1 && x < N && y > -1 && y < M && z > -1 && z < H) { //is in range?			
			if (board[x][y][z] == 0) { // is raw tomato??
				ripen++;
				from = arr.front().pos_from;
				cnt = arr.front().pos_cnt;
				if (raw == ripen) {
					cout << cnt;
					break;
				}
				arr.pop();
				board[x][y][z] = 1;
				if (from == 0) // no going to back!
					from = 1;
				else if (from == 1)
					from = 0;
				else if (from == 2)
					from = 3;
				else if (from == 3)
					from = 2;
				else if (from == 4)
					from = 5;
				else if (from == 5)
					from = 4;

				for (int i = 0; i < 6; i++)
					if (i != from)
						arr.push({ x + m1[i], y + m2[i], z+ m3[i], i, cnt + 1});
			}
			else
				arr.pop();
		}
		else
			arr.pop();
	}
	if (raw != ripen) 
		cout << -1;
}
int main(void) {
	scanf("%d %d %d", &M, &N, &H);
	int num;
	for (int l = 0; l < H; l++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &num);
				board[i][j][l] = num;
				if (num == 1)
					for (int k = 0; k < 6; k++)
						arr.push({ i + m1[k], j + m2[k], l + m3[k],  k, 1 });
				else if (num == 0)
					raw++;
			}
		}
	}
	if (raw != 0)
		DFS();
	else
		cout << 0;
	return 0;
}