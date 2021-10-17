#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string str, ans = "";
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c >= 'a' && c <= 'z') {
			c -= 'a';
			c += 'A';
		}
		else {
			c -= 'A';
			c += 'a';
		}
		ans = ans + c;
	}
	cout << ans;
	return 0;
}