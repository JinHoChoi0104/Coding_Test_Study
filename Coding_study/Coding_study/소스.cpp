#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int ans = max(c - b, b - a);
	if (ans == 0)
		cout << 0;
	else
		cout << ans - 1;
	return 0;
}