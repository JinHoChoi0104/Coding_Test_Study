#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a * c == b * b) 
			cout << "GP " << b * c / a << "\n";
		else
			cout << "AP " << b + c - a << "\n";
	}
	return 0;
}