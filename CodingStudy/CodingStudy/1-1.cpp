#include <iostream>
using namespace std;

unsigned long memo[3];
// P[n] = P[n-1] + P[n-5] (n>=6)
// P[1~5] = {1, 1, 1, 2 ,2}

int main() {
	// Dynamic Programming (µ¿Àû °èÈ¹¹ý)
	// solving problem by breaking big problem into smaller problems

	// to solve problem by Dynamic Programming, two properties must be satisfied
	// 1. Overlapping Subproblem    2. Optimal Substructure

	// in Dynamic Programming, you should solve each Subproblems only onc
	// because of Optimal Substructure same Subproblems have same answer
	// Therefore, once you have found the answer, you memorize it in the cache
	// and this is called 'Memoization'

	// two ways of solving
	// 1. Top-down : breaking into smaller problems, using recursion calling
	// 2. Bottom-up : strating from smaller problems to bigger problems, mostly using loop

	int N;
	cin >> N;

	
	unsigned long* arr = new unsigned long[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (N >= 4) {
		memo[0] = arr[N - 1] + arr[N - 3] + arr[N - 4]; // oxoo
		memo[1] = arr[N - 1] + arr[N - 3]; //oxox
		memo[2] = arr[N - 1] + arr[N - 2] + arr[N - 4]; //ooxo
	}
	else if (N == 3) {
		memo[0] = 0;
		memo[1] = arr[N - 1] + arr[N - 2];
		memo[2] = arr[N - 1] + arr[N - 3];
	}
	else if (N == 2) {
		memo[0] = arr[N - 1] + arr[N - 2];
		memo[1] = arr[N - 1];
		memo[2] = 0;
	}
	else {
		memo[0] = arr[N - 1];
		memo[1] = arr[N - 1];
		memo[2] = arr[N - 1];
	}

	unsigned long a, b, c;
	for (int i = N - 5; i > -1; i--) {
		a = memo[0];
		b = memo[1];
		c = memo[2];

		memo[2] = b + arr[i];
		memo[0] = c + arr[i];
		if (a > c)
			memo[1] = a;
		else
			memo[1] = c;
	}
	
	unsigned long max = memo[0];

	for (int i = 1; i < 3; i++) 
		if (max < memo[i])
			max = memo[i];

	cout << max;
	
	return 0;
}