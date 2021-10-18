#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string num;
	cin >> num;
	int tmp = 0, i = 0, len = num.size();
	if (len % 3 == 1) {
		cout << num[0];
		i = 1;
	}
	else if (len % 3 == 2) {
		cout << ((num[0] - '0') * 2) + (num[1] - '0');
		i = 2;
	}
	for (; i < len; i += 3) {
		cout << ((num[i] - '0') * 4) + ((num[i + 1] - '0') * 2) + (num[i + 2] - '0');
	}
	return 0;
}