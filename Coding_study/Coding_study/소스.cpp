#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int a1 = stoi(str1.substr(0,2)), a2 =stoi(str1.substr(3,2)), a3 = stoi(str1.substr(6, 2));
	int b1 = stoi(str2.substr(0, 2)), b2 = stoi(str2.substr(3, 2)), b3 = stoi(str2.substr(6, 2));
	if (b1 < a1) 
		b1 += 24;
	else if (b1 == a1) {
		if (b2 < a2)
			b1 += 24;
		else if (b2 == a2 && b3 < a3)
			b1 += 24;
	}
	if (a3 > b3) {
		b3 += 60;
		if (b2 == 0) {
			b1--;
			b2 += 60;
		}
		b2--;
	}
	b3 -= a3;
	if (a2 > b2) {
		b2 += 60;
		b1--;
	}
	b2 -= a2;
	b1 -= a1;
	cout.width(2);
	cout.fill('0');
	cout << b1 << ":";
	cout.width(2);
	cout.fill('0');
	cout << b2 << ":";
	cout.width(2);
	cout.fill('0');
	cout << b3;
	return 0;
}