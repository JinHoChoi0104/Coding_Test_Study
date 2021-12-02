#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	b += c;
	if (b >= 60) {
		a += b / 60;
		b %= 60;
		if (a >= 24)
			a -= 24;
	}
	cout << a << " " << b;
	return 0;
}	