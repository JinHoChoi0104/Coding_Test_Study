#include <iostream>
#define MAXVALUE 2

using namespace std;

int mini = 100000;
unsigned long memo[100000];

// BAEKJOON 1436
// solving in a Top-down way
void make_one(int n, int level) {
	if (n == 1) {
		if (mini > level)
			mini = level;
	}
	else if (n % 3 == 0 && n % 2 == 0) {
		if (mini > level)
			make_one(n / 3, level + 1);
		if (mini > level)
			make_one(n / 2, level + 1);
	}
	else if (n % 3 == 0) {
		if (mini > level)
			make_one(n / 3, level + 1);
		if (mini > level)
			make_one(n - 1, level + 1);
	}
	else if (n % 2 == 0) {
		if (mini > level)
			make_one(n / 2, level + 1);
		if (mini > level)
			make_one(n - 1, level + 1);
	}
	else {
		if (mini > level)
			make_one(n - 1, level + 1);
	}

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

	// divide in to 4 cases depending on whether it is divided by 2 and 3
	make_one(N, 0);
	
	cout << mini;
	return 0;
}