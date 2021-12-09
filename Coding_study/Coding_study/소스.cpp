#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b;
	string str;
	while (1) {
		cin >> str >> a >> b;
		if (str == "#")
			break;
		cout << str;
		if (a > 17 || b >= 80)
			cout << " Senior\n";
		else
			cout << " Junior\n";
	}
	return 0;
}