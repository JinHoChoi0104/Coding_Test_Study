#include <iostream>
#include <math.h>
using namespace std;

int ans = 0;
void dividing(int len, int r, int c) {
	if (len == 0)
		return;

	if (r >= len && c >= len) {
		ans += pow(len, 2) * 3;
		r -= len, c -= len;
		dividing(len / 2, r, c);
	}
	else if (r >= len) {
		ans += pow(len, 2) * 2;
		r -= len;
		dividing(len / 2, r, c);
	}
	else if (c >= len) {
		ans += pow(len, 2) * 1;
		c -= len;
		dividing(len / 2, r, c);
	}
	else {
		dividing(len / 2, r, c);
	}
}

int main() {
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	int len = pow(2, N - 1);
	dividing(len, r, c);

	printf("%d", ans);
	return 0;
}