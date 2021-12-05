#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num1 = 3, num2=6, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans += num1;
		num1 += num2;
		num2 += 3;
	}
	cout << ans;
	return 0;
}	