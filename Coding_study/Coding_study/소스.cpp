#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, num;
	int T[302], W[302];
	T[1] = 1;
	T[2] = 3;
	W[1] = 1 * T[2];
	for (int i = 2; i <= 300; i++) {
		T[i + 1] = T[i] + i + 1;
		W[i] = W[i - 1] + T[i+1] * i;
	}

	for (cin >> N; N-- > 0;) {
		cin >> num;
		cout << W[num] << "\n";
	}

	return 0;
}