#include <iostream>
#include <vector>
using namespace std;

#define Period 1500000
/*
Pisano Period:
If divide fibonacci by M, remain occurs period.

if M = 10 ^ k (k > 2)
Period P = 15 * 10^(k-1)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> fibo(Period);
	long long n;
	cin >> n;
	n %= Period;
	fibo[0] = 0, fibo[1] = 1;

	for (int i = 2; i <= n; i++) 
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000;
	cout << fibo[n];

	return 0;
}