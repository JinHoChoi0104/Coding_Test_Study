#include <iostream>
using namespace std;

long int memo[1500001]; //memorize subproblem's information
// 1 <= N <= 1,000,000
// 1 <= x <= 500,000
// 1 <= y <= 1,000,000
// 1 <= x + y <= 1,500,000

long int factorial(int n) {
	if (n == 0 || n == 1)
		n = 1;
	else 
		for (int i = n - 1; i > 0; i--) {
			n %= 15746;
			n *= i;
//			n %= 15746;
		}
	return n;
}

int tile(int x, int y) {
	if (memo[x + y] < 0) {
		memo[x + y] = factorial(x + y);
		cout << x << " + "<< y << " : " << memo[x + y] << endl;
	}
		//memo[(x + y) % 15746] = factorial((x + y) % 15746);
	if (memo[x] < 0) {
		memo[x] = factorial(x);
		cout << x  << " : " << memo[x] << endl;
	}
	if (memo[y] < 0) {
		memo[y] = factorial(y);
	//	cout << memo[y] << endl;
		cout << y << " : " << memo[y] << endl;
	}
	//cout << x << " " << y << " " << x + y << endl;
	//cout << memo[x] << " " << memo[y] << " " << memo [x + y] << endl;
	return memo[x + y] / memo[x] / memo[y];
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

	
	int N;
	//cout << factorial(21);
	cin >> N;

	for (int i = 0; i < 1500001; i++) 
		memo[i] = -1;

	int sum = 0;
	// 1. get combination with repetition of give number N by '00' and '1'
	for (int i = 0; i < N / 2 + 1; i++) { // if) N = 4, 5 then N/2 = 2
		//sum %= 15746;
		sum += tile(i, N - 2 * i); // 2. get permutation of N's combination of '00' and '1', and then sum them all
		cout << i << " " << N - 2 * i << " => " << sum << endl;
	//	cout << sum << endl;
	
	}
	cout << sum % 15746;
	
	return 0;
}