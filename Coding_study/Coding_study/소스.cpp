#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int tmp = (a - 1) / b;
	cout << tmp * c * d;
	
	return 0;
}