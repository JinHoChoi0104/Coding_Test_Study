#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num;
	while (1) {
		cin >> num;
		if (num == 0)
			break;
		int ans = 0;
		while (num) {
			ans += num % 10;
			num /= 10;
			if (num == 0) {
				if (ans < 10)
					break;
				else {
					num = ans;
					ans = 0;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}