// BAEKJOON 13460
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class ball_state {
public:
	int R[2]; //[y][x]
	int B[2];

	int n;//how many moves have done?

	//from where?
	bool right = false;
	bool left = false;
	bool up = false;
	bool down = false;

	ball_state(int RY, int RX, int BY, int BX, bool _right, bool _left, bool _up, bool _down, int _n) {
		R[0] = RY;
		R[1] = RX;
		B[0] = BY;
		B[1] = BX;

		n = _n;

		right = _right;
		left = _left;
		up = _up;
		down = _down;
	}
};

bool board[10][10];
int M = 0, N = 0; // board size
int OY = 0, OX = 0;
queue <ball_state> arr;

bool goRight(int RY, int RX, int BY, int BX, int n ) {
	int pre_RY = RY; //previous position
	int pre_RX = RX;
	int pre_BY = BY;
	int pre_BX = BX;

	//check if R and B are in same horizontal state
	if (RY == BY ) {
		//if so move rightest ball first and then move another ball
		if (RX > BX) {
			while (board[RY][RX + 1]) {
				RX++;
				if (RY == OY && RX == OX)
					break;
			}
			if(RY != OY || RX != OX)
				board[RY][RX] = false;
			while (board[BY][BX + 1]) {
				BX++;
				if (BY == OY && BX == OX)
					break;
			}
			board[RY][RX] = true;
		}
		else {
			while (board[BY][BX + 1]) {
				BX++;
				if (BY == OY && BX == OX)
					return false;
			}
			board[BY][BX] = false;
			while (board[RY][RX + 1]) {
				RX++;
				if (RY == OY && RX == OX)
					return true;
			}
			board[BY][BX] = true;
		}
	}
	else { //else just move
		while (board[RY][RX + 1]) {
			RX++;
			if (RY == OY && RX == OX)
				return true;
		}
		while (board[BY][BX + 1]) {
			BX++;
			if (BY == OY && BX == OX)
				return false;
		}
	}
	

	//case 1: no movement -> no push
	//case 2: 1 movement 
	//case 2-a: R goal in ->alert
	//case 2-b: B goal in -> no push
	//case 3: 2 movement
	//case 3-a : R goal in ->alert 
	//case 3-b : B goal in -> no push
	//case 3-c: R and B boath goal in -> no push
	//save ball state to queue

	if (BY == OY && BX == OX);//no push
	else if (RY == OY && RX == OX)
		return true;
	else if(n < 9)
		if (pre_RY != RY || pre_RX != RX || pre_BY != BY || pre_BX != BX) // if no move has done, no push
			arr.push(ball_state(RY, RX, BY, BX, true, false, false, false, n + 1));
	return false;
}

bool goLeft(int RY, int RX, int BY, int BX, int n) {
	int pre_RY = RY;
	int pre_RX = RX;
	int pre_BY = BY;
	int pre_BX = BX;
	
	if (RY == BY) {
		if (RX < BX) {
			while (board[RY][RX - 1]) {
				RX--;
				if (RY == OY && RX == OX)
					break;
			}
			if (RY != OY || RX != OX) {
				board[RY][RX] = false;
			}
			while (board[BY][BX - 1]) {
				BX--;
				if (BY == OY && BX == OX)
					return false;
			}
			board[RY][RX] = true;
		}
		else {
			while (board[BY][BX - 1]) {
				BX--;
				if (BY == OY && BX == OX)
					return false;
			}
			board[BY][BX] = false;
			while (board[RY][RX - 1]) {
				RX--;
				if (RY == OY && RX == OX)
					return true;
			}
			board[BY][BX] = true;
		}
	}
	else {
		while (board[RY][RX - 1]) {
			RX--;
			if (RY == OY && RX == OX)
				break;
		}
		while (board[BY][BX - 1]) {
			BX--;
			if (BY == OY && BX == OX)
				break;
		}
	}

	if (BY == OY && BX == OX);//no push
	else if (RY == OY && RX == OX) 
		return true;
	else if (n < 9)
		if (pre_RY != RY || pre_RX != RX || pre_BY != BY || pre_BX != BX)
			arr.push(ball_state(RY, RX, BY, BX, false, true, false, false, n + 1));
	return false;
}


bool goUp(int RY, int RX, int BY, int BX, int n) {
	int pre_RY = RY;
	int pre_RX = RX;
	int pre_BY = BY;
	int pre_BX = BX;

	if (RX == BX) {
		if (RY < BY) {
			while (board[RY - 1][RX]) {
				RY--;
				if (RY == OY && RX == OX)
					break;
			}
			if (RY != OY || RX != OX)
				board[RY][RX] = false;
			while (board[BY - 1][BX]) {
				BY--;
				if (BY == OY && BX == OX)
					return false;
			}
			board[RY][RX] = true;
		}
		else {
			while (board[BY - 1][BX]) {
				BY--;
				if (BY == OY && BX == OX)
					return false;
			}
			board[BY][BX] = false;
			while (board[RY - 1][RX]) {
				RY--;
				if (RY == OY && RX == OX)
					break;
			}
			board[BY][BX] = true;
		}
	}
	else {
		while (board[RY - 1][RX]) {
			RY--;
			if (RY == OY && RX == OX)
				break;
		}
		while (board[BY - 1][BX]) {
			BY--;
			if (BY == OY && BX == OX)
				break;
		}
	}

	if (BY == OY && BX == OX); 
	else if (RY == OY && RX == OX) 
		return true;
	else if (n < 9) 
		if (pre_RY != RY || pre_RX != RX || pre_BY != BY || pre_BX != BX) 
			arr.push(ball_state(RY, RX, BY, BX, false, false, true, false, n + 1));
	
	return false;
}

bool goDown(int RY, int RX, int BY, int BX, int n) {
	int pre_RY = RY;
	int pre_RX = RX;
	int pre_BY = BY;
	int pre_BX = BX;

	if (RX == BX) {
		if (RY > BY) {
			while (board[RY + 1][RX]) {
				RY++;
				if (RY == OY && RX == OX)
					break;
			}
			if (RY != OY || RX != OX)
				board[RY][RX] = false;
			while (board[BY + 1][BX]) {
				BY++;
				if (BY == OY && BX == OX)
					return false;
			}
			board[RY][RX] = true;
		}
		else {
			while (board[BY + 1][BX]) {
				BY++;
				if (BY == OY && BX == OX)
					return false;
			}
			board[BY][BX] = false;
			while (board[RY + 1][RX]) {
				RY++;
				if (RY == OY && RX == OX)
					break;
			}
			board[BY][BX] = true;
		}
	}
	else {
		while (board[RY + 1][RX]) {
			RY++;
			if (RY == OY && RX == OX)
				break;
		}
		while (board[BY + 1][BX]) {
			BY++;
			if (BY == OY && BX == OX)
				break;
		}
	}

	if (BY == OY && BX == OX); //no push
	else if (RY == OY && RX == OX) 
		return true;
	else if (n < 9) 
		if (pre_RY != RY || pre_RX != RX || pre_BY != BY || pre_BX != BX) 
			arr.push(ball_state(RY, RX, BY, BX, false, false, false, true, n + 1));
	
	return false;
}

void BFS(){
	ball_state ball = arr.front();
	int num = -1;
	while (!arr.empty()) {
		ball = arr.front();
		arr.pop();
		if (!ball.left) { //if ball went from left you don't have to go to right
			if (goRight(ball.R[0], ball.R[1], ball.B[0], ball.B[1], ball.n)) {
				num = ball.n + 1;
				break;
			}
		}
		if (!ball.right) {
			if (goLeft(ball.R[0], ball.R[1], ball.B[0], ball.B[1], ball.n)) {
				num = ball.n + 1;
				break;
			}
		}
		if (!ball.up) {
			if (goDown(ball.R[0], ball.R[1], ball.B[0], ball.B[1], ball.n)) {
				num = ball.n + 1;
				break;
			}
		}
		if (!ball.down) {
			if (goUp(ball.R[0], ball.R[1], ball.B[0], ball.B[1], ball.n)) {
				num = ball.n + 1;
				break;
			}
		}
		if (ball.n == 10)
			break;
	}
	cout << num;
}

int main(void) {
	scanf("%d %d", &N, &M); //[N][M]
	char c;
	
	int B[2];
	int R[2];
	char in_board[10][10];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> in_board[i][j];
		
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (in_board[i][j] == '#')
				board[i][j] = false;
			else {
				board[i][j] = true;
				if (in_board[i][j] == 'B') {
					B[0] = i;
					B[1] = j;
				}
				else if (in_board[i][j] == 'R') {
					R[0] = i;
					R[1] = j;
				}
				else if (in_board[i][j] == 'O') {
					OY = i;
					OX = j;
				}
			}
		}
	}

	arr.push(ball_state(R[0], R[1], B[0], B[1], false, false, false, false,0));
	
	BFS();

	return 0;
}