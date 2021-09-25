#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll num, tmp = 1;
	int cnt=0;
	cin >>  num;
	if (num == 0) {
		cout << 0;
		return 0;
	}
	num = abs(num); //계산 편의를 위해 절대값
	
	//최소로 이동하기 위해서 목표치보다는 작은 가장 큰 2의 제곱수를 구한다
	while (num >= tmp) { 
		tmp *= 2;
		cnt++;
	}
	tmp /= 2;
	
	while (1) {
		if (num > 0) //앞뒤로 왔다갔다
			num -= tmp;
		else
			num += tmp;

		if (num == 0 && tmp == 1) { //이동하는 중간에 0은 나올 수가 없으므로 -1
			cout << cnt;
			return 0;
		}
		if (num == 0) {
			cout << -1;
			return 0;
		}
		tmp /= 2;
	}

	return 0;
}