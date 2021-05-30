#include <iostream>
using namespace std;

int memo[50][50][50]; //memorize subproblem's information

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20) 
		return w(20, 20, 20);

	if (a < b && b < c) {
		if (memo[a][b][c - 1] < 0)
			memo[a][b][c - 1] = w(a, b, c - 1);
		if (memo[a][b - 1][c - 1] < 0)
			memo[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		if (memo[a][b - 1][c] < 0)
			memo[a][b - 1][c] = w(a, b - 1, c);
		return memo[a][b][c - 1] + memo[a][b - 1][c - 1] - memo[a][b - 1][c];
	}
	else {
		if (memo[a - 1][b][c] < 0)
			memo[a - 1][b][c] = w(a - 1, b, c);
		if (memo[a - 1][b - 1][c] < 0)
			memo[a - 1][b - 1][c] = w(a - 1, b - 1, c);
		if (memo[a - 1][b][c - 1] < 0)
			memo[a - 1][b][c - 1] = w(a - 1, b, c - 1);
		if (memo[a - 1][b - 1][c - 1] < 0)
			memo[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
		return memo[a - 1][b][c] + memo[a - 1][b - 1][c] + memo[a - 1][b][c - 1] - memo[a - 1][b - 1][c - 1];
	}
}

int main() {
	// Dynamic Programming (µ¿Àû °èÈ¹¹ý)
	// solving problem by breaking big problem into smaller problems

	// to solve problem by Dynamic Programming, two properties must be satisfied
	// 1. Overlapping Subproblem    2. Optimal Substructure

	// in Dynamic Programming, you should solve each Subproblems only onc
	// because of Optimal Substructure same Subproblems have same answer
	// Therefore, once you have found the answer, you memorize it in the cache
	// and this is called 'Memoization'
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				memo[i][j][k] = -1;
			}
		}
	}

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w("<<a<<", "<<b<<", "<< c << ") = " << w(a, b, c) << endl;		
	}

	return 0;
}