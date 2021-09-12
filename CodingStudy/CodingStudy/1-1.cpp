#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int num, t = 5, ans = 0;
	while (t-- > 0) {
		scanf("%1d", &num);
		ans += pow(num, 5);
	}
	printf("%d", ans);
	return 0;
}