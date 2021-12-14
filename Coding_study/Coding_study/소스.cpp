#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c, num;
	cin >> a >> b >> c;
	if (a * b - c > 0)
		cout << a * b - c;
	else
		cout << 0;
	return 0;
}