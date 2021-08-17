#include <iostream>
using namespace std;
int main() {
	double a, d, k, sum = 0, remain = 1;
	scanf("%lf %lf %lf", &a, &d, &k);
	k = 1 + (k / 100), d /= 100;
	int cnt = 1;
	while (d < 1) {
		sum += cnt * remain * d;
		remain *= (1 - d);
		d *= k;
		cnt++;
	}
	printf("%.7f", (sum + cnt * remain) * a);
	return 0;
}