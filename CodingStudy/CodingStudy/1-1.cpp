#include <iostream>
using namespace std;

#define ll long long

int N, arr[5][5], ans[5][5];

void pow() { // get Squared of A^n
	int tmp[5][5];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < N; k++)
				tmp[i][j] += ans[i][k] * ans[k][j];
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans[i][j] = tmp[i][j] % 1000;
}

void getSquared(ll n) { // get A^n
	if (n == 1) return;

	getSquared(n / 2); // get A^(n/2)
	pow();
	if (n % 2 != 0) { // if n is odd num
		int tmp[5][5];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				tmp[i][j] = 0;
				for (int k = 0; k < N; k++)
					tmp[i][j] += ans[i][k] * arr[k][j];
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans[i][j] = tmp[i][j] % 1000;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> N >> n;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			ans[i][j] = arr[i][j] % 1000;
		}		

	getSquared(n);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cout << ans[i][j] <<" ";
		cout << "\n";
	}
	return 0;
}