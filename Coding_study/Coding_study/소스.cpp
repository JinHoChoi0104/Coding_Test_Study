#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num;
	cin >> num;
	cout << num * 78 / 100 << " ";
	int tmp = num * 20 / 100 * 22 / 100;
	cout << num - tmp;
	return 0;
}