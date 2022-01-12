#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num, tmp;
	cin >> num;
	while (1) {
		cin >> tmp;
		if (tmp == 0)
			break;
		if (tmp % num == 0)
			cout << tmp << " is a multiple of " << num << ".\n";
		else
			cout << tmp << " is NOT a multiple of " << num << ".\n";
	}
	return 0;
}