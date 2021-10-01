#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num, N, ans = 0, tmp = 1;;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 1) {
			ans += tmp;
			tmp++;
		}
		else
			tmp = 1;
	}
	cout << ans;
	return 0;
}