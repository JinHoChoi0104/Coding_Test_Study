#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num;
	for (cin >> T; T-- > 0;) {
		cin >> num;
		int cnt = 0;
		while (num > 0) {
			if (num % 2 == 1)
				cout << cnt <<" ";
			cnt++;
			num /= 2;
		}
		cout << "\n";
	}
	return 0;
}