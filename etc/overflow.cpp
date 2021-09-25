#include <iostream>
using namespace std;

int main(void) {
	long long n1 = 1000000;
	int n2 = 1000000;
	long long ans1 = 0, ans2 = 0;

	ans1 = n1 * n1;
	ans2 = n2 * n2;

	cout << "operating with (long long n) ans1: " << ans1 << endl;
	cout << "operating with (int n) ans2: " << ans2 << endl;

	return 0;
}