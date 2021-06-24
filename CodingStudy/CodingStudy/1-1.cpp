// BAEKJOON 2206
#include <iostream>
using namespace std;

#include <queue>

class jurney {
public:
	int y;
	int x;
	bool crushed;
	int cnt;
	jurney(int _y, int _x, bool _crushed, int _cnt) {
		y = _y;
		x = _x;
		crushed = _crushed;
		cnt = _cnt;
	}
};

bool isVisitable(int toY, int toX, bool* obstacle[], bool* uncrushed_visited[], bool* crushed_visited[], int N, int M, bool crushed) {
	if (toX > -1 && toX < M) // check if it is in range
		if (toY > -1 && toY < N)
			if (crushed) { //if it has crushed obstacle already => can't crush obstacle anymore
				if (!obstacle[toY][toX] && !crushed_visited[toY][toX])
					return true;
				else
					return false;
			}
			else {// if is hasn't crushed obstacle yet
				if (obstacle[toY][toX]) {
					if (!crushed_visited[toY][toX])  //it will crush obstacle
						return true;
					else
						return false;
				}
				else {
					if (!uncrushed_visited[toY][toX]) //if not visited
						return true;	
					else
						return false;
				}
			}
		
	return false;
}

void bfs(int fromY, int fromX, bool* obstacle[], bool* uncrushed_visited[], bool* crushed_visited[], int N, int M){
	queue <jurney> navi;
	navi.push(jurney(fromY, fromX, false, 1));
	uncrushed_visited[fromY][fromX] = true;

	int X, Y, cnt;
	bool crush;
	while (!navi.empty()) {
		X = navi.front().x;
		Y = navi.front().y;
		crush = navi.front().crushed;
		cnt = navi.front().cnt;
		navi.pop();
	
		if (Y == N - 1 && X == M - 1) {
			cout << cnt;
			break;
		}
		if (isVisitable(Y, X + 1, obstacle, uncrushed_visited, crushed_visited, N, M, crush)) {
			if (obstacle[Y][X + 1])
				navi.push(jurney(Y, X + 1, true, cnt + 1));
			else
				navi.push(jurney(Y, X + 1, crush, cnt + 1));	
			if (!crush && !obstacle[Y][X + 1]) 
				uncrushed_visited[Y][X + 1] = true;
			else 
				crushed_visited[Y][X + 1] = true;

		}
		if (isVisitable(Y + 1, X, obstacle, uncrushed_visited, crushed_visited, N, M, crush)) {
			if (obstacle[Y + 1][X])
				navi.push(jurney(Y + 1, X, true, cnt + 1));
			else
				navi.push(jurney(Y + 1, X , crush, cnt + 1));
			if (!crush && !obstacle[Y + 1][X]) 
				uncrushed_visited[Y + 1][X] = true;
			else 
				crushed_visited[Y + 1][X] = true;
	
		}
		if (isVisitable(Y, X - 1, obstacle, uncrushed_visited, crushed_visited, N, M, crush)) {
			if (obstacle[Y][X - 1])
				navi.push(jurney(Y, X - 1, true, cnt + 1));
			else
				navi.push(jurney(Y, X - 1, crush, cnt + 1));
			if (!crush && !obstacle[Y][X - 1])
				uncrushed_visited[Y][X - 1] = true;
			else
				crushed_visited[Y][X - 1] = true;
		}
		if (isVisitable(Y - 1, X, obstacle, uncrushed_visited, crushed_visited, N, M, crush)) {
			if (obstacle[Y - 1][X])
				navi.push(jurney(Y - 1, X, true, cnt + 1));
			else
				navi.push(jurney(Y - 1, X, crush, cnt + 1));
			if (!crush && !obstacle[Y - 1][X])
				uncrushed_visited[Y - 1][X] = true;
			else
				crushed_visited[Y - 1][X] = true;
		}
	}
	if (Y == N - 1 && X == M - 1);
	else
		cout << "-1";
}

int main() {
	int N, M; //map's size , N = y, M = x
	cin >> N >> M;
		
	int input = 0;
	
	bool** obstacle = (bool**)malloc(sizeof(bool*) * (N));
	bool** uncurshed_visited = (bool**)malloc(sizeof(bool*) * (N));
	bool** curshed_visited = (bool**)malloc(sizeof(bool*) * (N));
	
	for (int i = 0; i < N; i++) {
		obstacle[i] = (bool*)malloc(sizeof(bool) * (M));
		uncurshed_visited[i] = (bool*)malloc(sizeof(bool) * (M));
		curshed_visited[i] = (bool*)malloc(sizeof(bool) * (M));
		for (int j = 0; j < M ; j++){
			scanf("%1d", &input); // get each number once, not using input such as \n
			obstacle[i][j] = input == 1 ? true : false;
			uncurshed_visited[i][j] = false;
			curshed_visited[i][j] = false;
		}
	}

	bfs(0, 0, obstacle, uncurshed_visited, curshed_visited, N, M);
}