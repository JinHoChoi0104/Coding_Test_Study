#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int a1, b1, c1, a2, b2, c2;
	int ans1, ans2, ans3;
	for (int i = 0; i < 3; i++) {
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		if (c2 < c1) {
			b2--;
			c2 += 60;
		}
		ans3 = c2 - c1;
		if (b2 < b1) {
			a2--;
			b2 += 60;
		}
		ans2 = b2 - b1;
		ans1 = a2 - a1;

		cout << ans1 << " " << ans2 << " " << ans3 << endl;
	}
	return 0;
}