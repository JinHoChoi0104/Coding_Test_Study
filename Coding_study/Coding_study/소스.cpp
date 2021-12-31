#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, w, h, num;
	cin >> n >> w >> h;
	int tmp = pow(w, 2) + pow(h, 2);
	tmp = sqrt(tmp);
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num <= tmp)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;
}