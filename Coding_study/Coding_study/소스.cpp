#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	double num, tmp;
	cin >> num;
	while (1) {
		cin >> tmp;
		if (tmp == 999)
			break;
		cout << fixed;
		cout.precision(2);
		cout << tmp - num << "\n";
		num = tmp;
	}
	return 0;
}