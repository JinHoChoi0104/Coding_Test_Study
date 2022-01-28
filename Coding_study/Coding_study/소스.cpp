#include <iostream>
using namespace std;
int main(){
	int num, tmp, ans = 0;
	cin >> num;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		if (num == tmp)
			ans++;
	}
	cout << ans;
	return 0;
} 