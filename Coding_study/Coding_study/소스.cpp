#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num = 2, tmp = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		num += tmp;
		tmp *= 2;
	}
	cout << num * num;
	return 0;
}