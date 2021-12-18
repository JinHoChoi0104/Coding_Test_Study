#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	long long T, num, cnt = 0;
	vector<long long> arr;
	for (cin >> T; T-- > 0;) {
		cin >> num;
		arr.push_back(num);
	}
	cin >> num;
	for (int i = 0; i < arr.size(); i++) {
		int tmp = arr[i];
		tmp += num - 1;
		tmp /= num;
		cnt += tmp;
	}
	cout << cnt * num;
	return 0;
}