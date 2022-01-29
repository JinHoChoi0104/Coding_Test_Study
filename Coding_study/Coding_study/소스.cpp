#include <iostream>
using namespace std;
int main(){
	//a1=5   an = 3n+1
	long long ans = 5, num;
	cin >> num;
	for (long long i = 2; i <= num; i++) {
		ans += 3 * i + 1;
	}
	cout << ans % 45678;
	return 0;
} 