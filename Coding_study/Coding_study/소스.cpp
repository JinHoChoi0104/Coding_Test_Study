#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num;
	cin >> num;
	if (num % 10 != 0) {
		cout << -1;
		return 0;
	}
	cout << num / 300 << " ";
	num %= 300;
	cout << num / 60 << " ";
	num %= 60;
	cout << num / 10;
	return 0;
}