#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	long long a, b;
	cin >> a >> b;
	if (a > b) {
		int k = a;
		a = b;
		b = k;
	}
	long long ans = a + b, tmp = b - a + 1;
	if (ans % 2 == 0)
		ans /= 2;
	else
		tmp /= 2;
	cout << ans * tmp;
	
	return 0;
}