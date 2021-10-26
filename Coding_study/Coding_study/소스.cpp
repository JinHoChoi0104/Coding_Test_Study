#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num, min_num = 101, sum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 0)
			continue;
		sum += num;
		min_num = min(min_num, num);
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum <<"\n"<< min_num;

	return 0;
}