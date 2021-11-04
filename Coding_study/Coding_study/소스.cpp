#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	double x, y, n;
	cin >> x >> y;
	double ans = x / y * 1000;
	for (cin >> n; n-- > 0;) {
		cin >> x >> y;
		double tmp = x / y * 1000;
		ans = min(ans, tmp);
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}