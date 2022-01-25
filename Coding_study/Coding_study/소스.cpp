#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t, num;
	for (cin >> t; t-- > 0;) {
		int sum = 0, ans = 100;
		for (int i = 0; i < 7; i++) {
			cin >> num;
			if (num % 2 != 0)
				continue;
			ans = min(ans, num);
			sum += num;
		}
		cout << sum << " " << ans << "\n";
	}
	return 0;
} 