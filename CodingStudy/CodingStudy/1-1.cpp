#include <iostream>
#include <cmath>

// BAEKJOOON 4948 *Prime Number Algorithm
// get Prime Number between given number N and 2N
// 1 <= N <= 123456

/* There are 2ways of geting Prime Number
 
 1. To find out whether Given numerb N is prime number
 divide N by 1 ~ sqrt(N) and if it is not divided then N is prime number 
 
 2. let's say we get prime numer in range of 1 ~ n
 multiple of 2 is not prime number, so exclude it
 multiple of 3 is not prime number, so exclude it
 multiple of 5 is not prime number, so exclude it
 multiple of 7 is not prime number, so exclude it ...
 do this until sqrt(N)
 numbers except excluded by the above process are prime number
*/
const int range = 123456;

int main()
{
	int N = 1;
	int cnt = 0;
	int arr[range * 2 + 1] = {0}; // 1: not prime number, 0: prime number
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= sqrt(2*range); i++) {
		if (arr[i] != 1) 
			for (int j = 2; j * i <=  range * 2; j++) 
				arr[i * j] = 1;
	}

	scanf("%d", &N);
	while (N != 0) {
		cnt = 0;
		for (int i = N + 1; i <= 2 * N; i++) 
			arr[i] == 0 ? cnt ++ : NULL;
		
		printf("%d\n", cnt);
		scanf("%d", &N);
	}
}