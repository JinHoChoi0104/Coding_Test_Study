#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num;
	for (cin >> T; T-- > 0;) {
		int tmp = 0;;
		for (cin >> num; num-- > 0;) {
			char a, b;
			cin >> a >> b;
			if (a == 'R') {
				if (b == 'S')
					tmp++;
				else if (b == 'P')
					tmp--;
			}
			else if (a == 'S') {
				if (b == 'P')
					tmp++;
				else if (b == 'R')
					tmp--;
			}
			else {
				if (b == 'R')
					tmp++;
				else if (b == 'S')
					tmp--;
			}
		}
		if (tmp > 0)
			cout << "Player 1\n";
		else if (tmp < 0)
			cout << "Player 2\n";
		else
			cout << "TIE\n";
	}
	return 0;
}