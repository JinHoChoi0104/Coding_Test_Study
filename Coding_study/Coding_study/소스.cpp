#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, M, L, cnt = -1, index = 0;
	cin >> N >> M >> L;
	vector<int>arr(50, 0);
	while (!arr.empty()) {
		int &tmp = arr[index];
		tmp++, cnt++;
		if (tmp % 2 == 1) {
			index += L;
			if (index >= N)
				index -= N;
		}
		else {
			index -= L;
			if (index < 0)
				index += N;
		}
		if (tmp == M) {
			cout << cnt;
			return 0;
		}
	}
	return 0;
}