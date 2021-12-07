#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c, d, num;
	cin >> num >> a >> b >> c >> d;
	int tmp1, tmp2;
	a += (c - 1);
	tmp1 = a / c;
	tmp1 = num - tmp1;
	b += (d - 1);
	tmp2 = b / d;
	tmp2 = num - tmp2;

	num = min(tmp1, tmp2);
	cout << num;
	return 0;
}