#include <iostream>

using namespace std;

long long arr[101][10];
# define mod 1000000000;

// BAEKJOON 10844
// solving in a Top-down way


// if) N = 1
// 1~9
// if) N = 2
// 01
// 10, 12
// 21, 23
// 32. 34
// ...
// 87, 89
// 98
// 2 * 8 + 1 = 17

// if) N = 3
// 010, 012
// 101, 121, 123
// 210, 213, 232, 234
// 321, 323, 343, 345
// ...
// 987, 989

// if) N = 4
// 0
// 1010, 1012, 12


// arr[n][i] = arr[n-1][i-1] + arr[n-1][i+1]

void easy_star(int n, int i) {

}

int main() {
	// Dynamic Programming (µ¿Àû °èÈ¹¹ý)
	// solving problem by breaking big problem into smaller problems

	// to solve problem by Dynamic Programming, two properties must be satisfied
	// 1. Overlapping Subproblem    2. Optimal Substructure

	// in Dynamic Programming, you should solve each Subproblems only once
	// because of Optimal Substructure same Subproblems have same answer
	// Therefore, once you have found the answer, you memorize it in the cache
	// and this is called 'Memoization'

	// two ways of solving
	// 1. Top-down : breaking into smaller problems, using recursion calling
	// 2. Bottom-up : strating from smaller problems to bigger problems, mostly using loop

	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) 
		arr[1][i] = 1;


	for (int n = 2; n <= N; n++) {
		for (int i = 1; i < 9; i++) {
			arr[n][i] = (arr[n - 1][i - 1] + arr[n - 1][i + 1]) % mod;
		}
		arr[n][0] = arr[n - 1][1] % mod;
		arr[n][9] = arr[n - 1][8] % mod;
	}

	long long stair = 0;
	for (int i = 1; i < 10; i++) 
		stair += arr[N][i];
	
	cout << stair % mod;
	
	return 0;
}