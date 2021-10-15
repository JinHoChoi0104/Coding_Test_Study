#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, L, ans = 0;
	cin >> N >> L;
	int i = 1;
	for (;; i++) {
		int num = i;
		bool isAble = true;
		while (num > 0) {
			if (num % 10 == L) {
				isAble = false;
				break;
			}
			num /= 10;
		}
		if (isAble)
			ans++;
		if (ans == N)
			break;
	}
	cout << i;
		
	return 0;
}