#include <iostream>
using namespace std;
#define M 1234567891
#define ll long long
ll LongPow(ll num, int n) {
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= num;
		ans %= M;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N;
	string str;
	cin >> N >> str;
	ll num = 0;
	for (int i = 0; i < N; i++) {
		ll tmp = str[i] - 'a' + 1;
		num += tmp * LongPow(31, i);
		num %= M;
	}
	cout << num;
	return 0;
} 