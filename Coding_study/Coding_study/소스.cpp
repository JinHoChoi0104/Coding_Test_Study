#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T;
	int a, b, c;
	for (cin >> T; T-- > 0;) {
		cin >> a >> b >> c;
		b -= c;
		if (a < b)
			cout << "advertise\n";
		else if (a == b)
			cout << "does not matter\n";
		else
			cout << "do not advertise\n";
	}
	return 0;
}