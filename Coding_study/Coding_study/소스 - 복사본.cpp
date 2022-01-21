#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num, ans1 = 0, ans2 = 0, a, b;
	for (cin >> num; num-- > 0; ) {
		cin >> a >> b;
		if (a > b)
			ans1++;
		else if (a < b)
			ans2++;
	}
	cout << ans1 << " " << ans2;
	return 0;
}