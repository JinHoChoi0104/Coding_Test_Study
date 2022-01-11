#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int index=0, ans=0, num;
	for (int i = 0; i < 5; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			cin >> num;
			tmp += num;
		}
		if (tmp > ans) {
			ans = tmp;
			index = i + 1;
		}
	}
	cout << index << " " << ans;
	return 0;
}