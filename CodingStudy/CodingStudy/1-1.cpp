// BAEKJOON 11729
// Hanoi Tower
#include <iostream>

int Hanoi_cnt(int n) {
	if (n == 1)
		return 1;
	else
		return Hanoi_cnt(n - 1) * 2 + 1;
}
void Hanoi(int from, int mid, int to, int n) {
	if (n == 1)
		printf("%d %d\n", from, to);
	
	else {
		Hanoi(from, to, mid, n - 1);
		Hanoi(from, mid, to, 1);
		Hanoi(mid, from, to, n - 1);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", Hanoi_cnt(N));
	Hanoi(1, 2, 3, N);
	
}