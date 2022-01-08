#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int B, N;
	while (1) {
		cin >> B >> N;
		if (B == 0 && N == 0)
			break;
		for (int i = 1; i <= B; i++) {
			int tmp = pow(i, N);
			if (tmp == B) {
				cout << i << "\n";
				break;
			}
			if (tmp > B) {
				int dif1 = B - pow(i - 1, N);
				int dif2 = tmp - B;
				if (dif1 > dif2)
					cout << i << "\n";
				else
					cout << i - 1 << "\n";
				break;
			}
		}
	}
	return 0;
}