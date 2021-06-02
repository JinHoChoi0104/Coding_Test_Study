#include <iostream>
using namespace std;

int memo[1000001];
// a[n] = a[n-1] + a[n-2]
// a[1] = 1
// a[2] = 2

int main() {
	// Dynamic Programming (µ¿Àû °èÈ¹¹ý)
	// solving problem by breaking big problem into smaller problems

	// to solve problem by Dynamic Programming, two properties must be satisfied
	// 1. Overlapping Subproblem    2. Optimal Substructure

	// in Dynamic Programming, you should solve each Subproblems only onc
	// because of Optimal Substructure same Subproblems have same answer
	// Therefore, once you have found the answer, you memorize it in the cache
	// and this is called 'Memoization'

	int N;
	cin >> N;

	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i < N+1; i++) 
		memo[i] = (memo[i - 1] + memo[i - 2])%15746;

	cout << memo[N];
	
	return 0;
}