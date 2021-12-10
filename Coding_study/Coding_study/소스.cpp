#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t, num;
	for (cin >> t; t-- > 0;) {
		cin >> num;
		int cnt = 0, tmp = num, num2 = num * num;
		while (tmp) {
			cnt++;
			tmp /= 10;
		}
		int di = 1;
		for (int i = 0; i < cnt; i++) {
			di *= 10;
		}
		num2 %= di;
		if (num2 == num)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}