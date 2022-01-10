#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	double a, b, c, d, max_num, tmp;
	cin >> a >> b >> c >> d;
	int ans = 0;
	max_num = a / c + b / d;
	tmp = c / d + a / b;
	if (tmp > max_num) {
		max_num = tmp;
		ans = 1;
	}
	tmp = d / b + c / a;
	if (tmp > max_num) {
		max_num = tmp;
		ans = 2;
	}
	tmp = b / a + d / c;
	if (tmp > max_num) {
		max_num = tmp;
		ans = 3;
	}
	cout << ans;
	return 0;
}