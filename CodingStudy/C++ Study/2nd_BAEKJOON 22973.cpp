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
	num = abs(num); //��� ���Ǹ� ���� ���밪
	
	//�ּҷ� �̵��ϱ� ���ؼ� ��ǥġ���ٴ� ���� ���� ū 2�� �������� ���Ѵ�
	while (num >= tmp) { 
		tmp *= 2;
		cnt++;
	}
	tmp /= 2;
	
	while (1) {
		if (num > 0) //�յڷ� �Դٰ���
			num -= tmp;
		else
			num += tmp;

		if (num == 0 && tmp == 1) { //�̵��ϴ� �߰��� 0�� ���� ���� �����Ƿ� -1
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