#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0)
			break;
		
		if (a + b <= c || a + c <= b || b + c <= a) {
			cout << "Invalid\n";
			continue;
		}

		if (a == b && b == c)
			cout << "Equilateral\n";
		else if (a == b || b == c || a == c)
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
	return 0;
}