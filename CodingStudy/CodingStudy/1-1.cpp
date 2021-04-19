#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	char x[10000], y[10000];
	int result[10000];
	strcpy(x, a.c_str());
	strcpy(y, b.c_str());
	int p = strlen(x), q = strlen(y);
	int len;

	if (p >= q) {
		len = p;
		for (int i = p - 1, j = q - 1; i > p - q - 1 ; i--, j--) 
			y[i] = y[j];
		for (int i = p - q - 1; i > -1; i--) 
			y[i] = '0';
	}
	else {
		len = q;
		for (int i = q - 1, j = p - 1; i > q - p - 1; i--, j--)
			x[i] = x[j];
		for (int i = q - p - 1; i > -1; i--)
			x[i] = '0';
	}


	int digi = 0, sum = 0;
	for (int i = len-1; i > -1; i--) {
		sum = (x[i] - '0') + (y[i] - '0') + digi;

		if (sum > 9) {
			result[len - i - 1] = sum % 10;
			digi = 1;
			if (i == 0) {
				result[len] = 1;
				len += 1;
				break;
			}
		}
		else {
			result[len - i - 1] = sum;
			digi = 0;
		}
	}

	for (int i = len - 1  ; i > - 1 ; i--) 
		cout << result[i];

	return 0;
}