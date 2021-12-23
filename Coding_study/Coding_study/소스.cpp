#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int ans = 0, num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		ans += num;
	}
	cout << ans;
	return 0;
}