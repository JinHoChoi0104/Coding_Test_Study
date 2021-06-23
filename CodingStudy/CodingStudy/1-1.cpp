// BAEKJOON 2667
#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>

bool isVisitable(int toX, int toY, bool* visited[], int N) {
	if(toX > -1 && toX < N)
		if (toY > -1 && toY < N)
			if(!visited[toX][toY]) //if not visited
				return true;
	return false;
}

void dfs(int fromY, int fromX, bool *visited[], int N, int *cnt) { //used recursion to implement dfs
	visited[fromY][fromX] = true;
	(*cnt)++;
	
	//RIGHT DOWN LEFT UP
	if (isVisitable(fromY, fromX+1, visited, N))
		dfs(fromY, fromX+1, visited, N, cnt);
	if (isVisitable(fromY+1, fromX, visited, N))
		dfs(fromY+1, fromX, visited, N, cnt);
	if (isVisitable(fromY, fromX-1, visited, N))
		dfs(fromY, fromX-1, visited, N, cnt);
	if (isVisitable(fromY-1, fromX, visited, N))
		dfs(fromY-1, fromX, visited, N, cnt);
}

int main() {
	int N; //map's size
	cin >> N;
		
	int input = 0;
	bool **visited = (bool**)malloc(sizeof(bool*) * (N));
	
	for (int i = 0; i < N; i++) {
		visited[i] = (bool*)malloc(sizeof(bool) * (N));
		for (int j = 0; j < N ; j++){
			scanf("%1d", &input); // get each number once, not using input such as \n
			visited[i][j] = input == 1 ? false : true;
		}
	}

	vector<int> house_set;
	int cnt;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (visited[i][j] == false) {
				dfs(i, j, visited, N, &cnt);
				house_set.push_back(cnt);
			}
		}

	cout << house_set.size() << endl;
	sort(house_set.begin(), house_set.end());
	for (int i = 0; i < house_set.size(); i++)
		cout << house_set[i] << endl;
}