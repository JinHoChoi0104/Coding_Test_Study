#include <iostream>
using namespace std;

bool isSame(string a, string b) {
	int len1 = a.size(), len2 = b.size();
	for (int i = 0; i < len1 * len2; i++) {
		if (a[i % len1] != b[i % len2])
			return false;
		if ((i+1) % len1 == 0 && (i+1) % len2 == 0)
			return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string a, b;
	cin >> a >> b;

	if (isSame(a, b))
		cout << 1;
	else
		cout << 0;
	return 0;
}