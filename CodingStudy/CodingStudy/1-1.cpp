#include <iostream>
using namespace std;

int memo[40][2]; //memorize subproblem's information
int memo2[40];

// n을 n-1, n-2로 나눈다 
// n-1이 구한적이 없으면 피보나치 아니면 패스

int fibonacci(int n) {
	if (n == 0) {
		memo2[0] = 0;
		memo[0][0] = 1;
		memo[0][1] = 0;
		return 0;
	}
	else if (n == 1) {
		memo2[1] = 1;
		memo[1][0] = 0;
		memo[1][1] = 1;
		return 1;
	}

	else {
		if (memo2[n - 1] < 0) {
			memo2[n - 1] = fibonacci(n - 1);
			
		}
		if (memo2[n - 2] < 0)
			memo2[n - 2] = fibonacci(n - 2);
	
		memo[n][0] = memo[n - 1][0] + memo[n - 2][0];
		memo[n][1] = memo[n - 1][1] + memo[n - 2][1];
		return memo2[n - 1] + memo2[n - 2];
	}
}

int main() {
	// Dynamic Programming (동적 계획법)
	// solving problem by breaking big problem into smaller problems

	// to solve problem by Dynamic Programming, two properties must be satisfied
	// 1. Overlapping Subproblem    2. Optimal Substructure

	// in Dynamic Programming, you should solve each Subproblems only onc
	// because of Optimal Substructure same Subproblems have same answer
	// Therefore, once you have found the answer, you memorize it in the cache
	// and this is called 'Memoization'

	int test_case;
	cin >> test_case;
	int *num = new int[test_case];
	for (int i = 0; i < test_case; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < test_case; i++) {
		for (int i = 0; i < 40; i++) {
			memo[i][0] = 0;
			memo[i][1] = 0;
			memo2[i] = -1;
		}
		fibonacci(num[i]);
		cout << memo[num[i]][0]<< " " <<memo[num[i]][1]<< endl;
	}

	return 0;
}