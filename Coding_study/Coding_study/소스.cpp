#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int ans = 0, sum = 0, a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		sum -= a;
		sum += b;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}