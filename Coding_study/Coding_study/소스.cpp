#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, num;
	cin >> a;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		a += num;
	}
	cin >> b;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		b += num;
	}
	if (a > b)
		cout << a;
	else
		cout << b;
	return 0;
}	