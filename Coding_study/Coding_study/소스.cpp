#include <iostream>
using namespace std;
int main(){
	int a, b, c, num;
	cin >> a >> b >> c >> num;
	int tmp = num % 60;
	c += tmp;
	if (c >= 60) {
		c -= 60;
		b++;
	}
	num -= tmp;
	num /= 60;
	tmp = num % 60;
	b += tmp;
	if (b >= 60) {
		b -= 60;
		a++;
	}
	num -= tmp;
	num /= 60;
	a += num;
	a %= 24;
	
	cout << a << " " << b << " " << c;
	return 0;
} 