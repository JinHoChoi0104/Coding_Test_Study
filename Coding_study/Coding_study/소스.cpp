#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int t;
	for (cin >> t; t-- > 0;) {
		char c;
		int tmp1 = 0, tmp2 = 0;
		for (int i = 0; i < 3; i++) {
			cin >> c;
			tmp1 += (c - 'A') * pow(26,2-i);
		}
		cin >> c;
		cin >> tmp2;

		if (abs(tmp1 - tmp2) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}
	return 0;
}	