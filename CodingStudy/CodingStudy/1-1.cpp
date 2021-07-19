#include<iostream>
using namespace std;

long long longPow(int n, int k) {
	long long num = 1;
	for (int i = 0; i < k; i++)
		num *= n;
	return num;
}

// 3^0 + 3^1 + 3^2 + ... + 3^(n-1) < 3^n

// numbers of SeanRin under 3^n are 2^(n-1) - 1 (because 0 is not SeanRin)
// it means 3^n are (2^n)th SeanRin

// if ( 2^(n-1) < N <= 2^n )
// then N include 3^n

long long GetSeanRin(long long n) {
	long long sum = 0;//SeanRin
	int k = 0;
	while (n > 0) {
		if (n == longPow(2, k)) {
			sum += longPow(3, k);
			n -= longPow(2, k);
		}
		else if (n > longPow(2, k))
			k++;
		else {
			sum += longPow(3, k - 1);
			n -= longPow(2, k - 1);
			k = 0;
		}
	}
	return sum;
}

int main(void) {
	int T;
	cin >> T;

	long long n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		printf("%lld\n", GetSeanRin(n));
	}
	return 0;
}