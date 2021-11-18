#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	long long X, Y;
	cin >> X >> Y;
	int Z = Y * 100 / X;
	if (X == Y || Z == 99) {
		cout << "-1";
		return 0;
	}
	long long left = 0, right = X, mid, num, ans;
	while (left <= right) {
		mid = (left + right) / 2;
		num = (Y+mid) * 100 / (X+mid);
		if (num != Z) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;
	return 0;
}