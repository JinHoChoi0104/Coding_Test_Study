#include <iostream>

using namespace std;


// BAEKJOON 1342
// Permutation(¼ø¿­) algorithm



int factorial(int num)
{
	if (num == 0)
		num = 1;
	for (int i = num-1; i > 0; i--)
		num *= i;
	return num;
}



int main() {
	cout << factorial(10);
	return 0;
}