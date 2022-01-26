#include <iostream>
using namespace std;
int main(){
	int num, cnt = 0, tmp = 4, sum = 1;
	cin >> num;
	while (num > 0) {
		num -= sum;
		sum += tmp;
		tmp += 4;
		cnt++;
		if (num < sum) {
			break;
		}
	}
	cout << cnt;
	return 0;
} 