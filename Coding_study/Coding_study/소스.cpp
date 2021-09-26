#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> M >> N;
	/*
	조합! mCn 구하면 된다
		 m!
	------------
	(m-n)! * n!
	*/
	int tmp1 = min(M - N, N), tmp2 = max(M - N, N); //tmp1 < tmp2
	ll ans = 1;

	for (ll i = tmp2 + 1; i <= M; i++)
		ans *= i;
	for (ll i = 1; i <= tmp1; i++)
		ans /= i;

	cout << ans;

	return 0;
}