#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int ans = 0, num;
	char c[5] = { 'E', 'A', 'B', 'C', 'D' };
	for (int j = 0; j < 3; j++) {
		ans = 0;
		for (int i = 0; i < 4; i++) {
			cin >> num;
			if (num == 0)
				ans++;
		}
		cout << c[ans] << "\n";
	}
	
	return 0;
}