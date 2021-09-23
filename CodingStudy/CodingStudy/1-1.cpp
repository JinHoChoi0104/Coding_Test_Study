#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int x, y, num = 0, tmp;
	for(int i=1; i<=9; i++)
		for (int j = 1; j <= 9; j++) {
			cin >> tmp;
			if (tmp > num) {
				x = i, y = j;
				num = tmp ;
			}

		}
	cout << num << "\n" << x << " " << y << "\n";
	return 0;
}