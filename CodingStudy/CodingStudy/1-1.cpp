#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

int N; //size of board
vector<vector<int>> board(101, vector<int>(101, 0)); //-1 bame, 0 nothing, 1: apple
queue<pair<int, int>> rout; //cnt, direction
list<pair<int, int>> baem; //save baem's position
int m[2][4] = { {-1, 0 ,1, 0}, {0, 1, 0, -1} }; // up, right, down, left

void checkR(int cnt, int& dir) { //check whether if has to turn
	if (cnt == rout.front().first) {
		dir += rout.front().second;
		if (dir == 4)
			dir = 0;
		else if (dir == -1)
			dir = 3;
		rout.pop();
	}
}

void dummy(int &cnt, int dir) {
	if (!rout.empty()) 
		checkR(cnt, dir);

	cnt++;
	int x = baem.front().first + m[0][dir];
	int y = baem.front().second + m[1][dir];

	if (x == 0 || y == 0 || x == N + 1 || y == N + 1 ) // if not in range 
		return;
	
	if (board[x][y] == 0) { // if no apple
		board[baem.back().first][baem.back().second] = 0;
		baem.pop_back();
	}

	if (board[x][y] == -1) // if it's head meet baem
		return;
	
	board[x][y] = -1; // beam has moved!!
	baem.push_front(make_pair(x, y));

	dummy(cnt, dir);
}

int main(void) {
	int K, L, x, y, cnt, time = 0;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &x, &y);
		board[x][y] = 1;
	}
	board[1][1] = -1; // put baem
	baem.push_back(make_pair(1, 1));
	char d;
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &cnt, &d);
		if (d == 'D')
			rout.push(make_pair(cnt, 1)); // == push(pair<int,int> (l, 2));
		else
			rout.push(make_pair(cnt, -1));
	}
	
	dummy(time, 1);
	printf("%d", time);
	return 0;
}