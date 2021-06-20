#include <iostream>
#include <cmath>
// BAEKJOOON 4948 *Prime Number Algorithm
// get Prime Number between given number N and 2N
// 1 <= N <= 123456

int isPrime(int n) {
	if (n <= 1)
		return 0; //1 is not prime number
	else if (n == 2)
		return 1; //2 is prime number
	else if (n % 2 == 0)
		return 0; //even number is not prime number
	else{
		for (int i = 3; i <= sqrt(n); i ++) {
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}

int main()
{
	int N = 1;
	int cnt = 0;
	int arr[123457 * 2];
	for (int i = 0; i < 123457 * 2; i++) {
		arr[i] = isPrime(i);
		//printf("%d is  %d\n", i, arr[i]);
	}
	while (N != 0) {
		scanf("%d", &N);
		cnt = 0;
		for (int i = N + 1; i <= 2 * N; i++) {
			cnt += arr[i];
		}
		printf("%d\n", cnt);
	}
}