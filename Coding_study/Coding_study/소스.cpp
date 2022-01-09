#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int ans1 = a * p;
	int ans2 = b;
	if (c < p) {
		int tmp = p - c;
		ans2 += tmp * d;
	}
	if (ans1 > ans2)
		cout << ans2;
	else
		cout << ans1;
	return 0;
}