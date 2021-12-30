#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t, num;
	for (cin >> t; t-- > 0;) {
		cin >> num;
		cout << "Pairs for " << num << ": ";
		for (int i = 1; i < (num+1) / 2; i++) {
			if (i != 1)
				cout << ", ";
			cout << i << " " << num - i;
		}
		cout << "\n";
	}
	return 0;
}