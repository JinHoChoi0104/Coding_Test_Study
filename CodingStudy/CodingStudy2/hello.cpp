#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, a, b;
	cout <<"hello";

	while (1) {
		cin >> T;
		if (T == 0) break;
		int ans = 1;
		for (int i = 0; i < T; i++) {
			cin >> a >> b;
			ans *= a;
			ans -= b;
		}
		cout << ans << "\n";
	}

	return 0;
}