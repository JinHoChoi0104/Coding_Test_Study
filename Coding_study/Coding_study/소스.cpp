#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num, T;
	for (cin >> T; T-- > 0;) {
		cin >> num;
		int a=0, b=0, c=0, d=0;
		while (num >= 25) {
			num -= 25;
			a++;
		}
		while (num >= 10) {
			num -= 10;
			b++;
		}
		while (num >= 5) {
			num -= 5;
			c++;
		}
		d = num;
		cout << a << " " << b << " " << c << " " << d << "\n";
	}
	return 0;
}