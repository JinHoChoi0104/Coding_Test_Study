#include <iostream>
#define MAXVALUE 2

using namespace std;

int mini = 100000;
unsigned long memo[100000];

// BAEKJOON 10844
// solving in a Top-down way


// if) N = 1
// 1~9
// if) N = 2
// 10, 12
// 21, 23
// 32. 34
// ...
// 87, 89
// 98
// 2 * 8 + 1 = 17

// if) N = 3
// 101, 121, 123
// 210, 213, 232, 234
// 321, 323, 343, 345
// ...
//


int main() {
	// Dynamic Programming (µ¿Àû °èÈ¹¹ı)
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
	
	
	
	return 0;
}