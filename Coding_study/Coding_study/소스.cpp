#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int num = c;
	for (int i = 3; i < n; i++)
		cin >> num;

	if (a + c == b * 2) {
		num += b - a;
	}
	else
		num *= b / a;
	cout << num;
	return 0;
}