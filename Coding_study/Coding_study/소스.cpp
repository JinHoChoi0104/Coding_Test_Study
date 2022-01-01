#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	cin >> str;
	int n = str.size();
	int r = sqrt(n), c;
	while (1) {
		if (n % r != 0) {
			r--;
			continue;
		}
		c = n / r;
		break;
	}
	int index = 0;
	char ch[101][101];
	for (int i = 0; i < c; i++) 
		for (int j = 0; j < r; j++) 
			ch[j][i] = str[index++];

	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			cout << ch[i][j];

	return 0;
}