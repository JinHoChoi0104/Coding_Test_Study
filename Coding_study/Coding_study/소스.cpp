#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c, ans;
	cin >> a >> b >> c;
	if (a == b && b == c) 
		ans = 10000 + a * 1000;
	else if (a == b || a==c) 
		ans = 1000 + a * 100;
	else if (b == c) 
		ans = 1000 + b * 100;
	else 
		ans = max({ a,b,c }) * 100;
	cout << ans;

	return 0;
}