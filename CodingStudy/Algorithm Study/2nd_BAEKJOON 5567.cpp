#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, from, to, cnt = 0;
	scanf("%d %d", &n, &m);
	vector <int> linked[501];
	vector <bool> isLinked(501, false);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &from, &to);
		//since this relationship is not one way relationship, should link to both side
		linked[from].push_back(to);
		linked[to].push_back(from);
	}
	for (int i = 0; i < linked[1].size(); i++) {
		from = linked[1][i]; //find out friends linked to No.1
		isLinked[from] = true;
		//find the friend connected with friend connected with No.1
		for (int j = 0; j < linked[from].size(); j++) { 
			to = linked[from][j];
			isLinked[to] = true;
		}
	}
	// check who are invited!
	for (int i = 2; i <= n; i++) 
		if (isLinked[i])
			cnt++;
	
	printf("%d", cnt);
	return 0;
}