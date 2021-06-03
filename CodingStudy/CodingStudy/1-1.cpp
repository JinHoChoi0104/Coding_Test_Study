#include <iostream>
using namespace std;

unsigned long memo[101];
// P[n] = P[n-1] + P[n-5] (n>=6)
// P[1~5] = {1, 1, 1, 2 ,2}

int main() {
	// Dynamic Programming (동적 계획법)
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

	int** arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < N; i++) { //세로 층 수
		for (int j = 1; j < i; j++) { //가로
			if (arr[i - 1][j - 1] > arr[i - 1][j])
				arr[i][j] += arr[i - 1][j-1];
			else
				arr[i][j] += arr[i - 1][j];
		}
		arr[i][0] += arr[i - 1][0];
		arr[i][i] += arr[i - 1][i - 1];
		
	}

	int max = arr[N - 1][0];
	for (int i = 1; i < N; i++) {
		if (max < arr[N - 1][i])
			max = arr[N - 1][i];
	}
	cout << max;
	
	return 0;
}