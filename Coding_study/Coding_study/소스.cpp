#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, n;
	cin >> a >> b >> n;
	if (a > b)
		a %= b;
	for (int i = 0; i < n; i++) { 
		a %= b;
		a *= 10;
	}
	cout << a/b;
	return 0;
}