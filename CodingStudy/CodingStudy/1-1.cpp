#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(void) {
	int N, x1, y1, x2, y2, x3, y3, pre, now, jump, max_jump=0;
	scanf("%d", &N);
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);

	pre = abs(x1 - x2) + abs(y1 - y2); //a1�� a2���� �Ÿ�
	ll max_len = pre;
	for (int i = 2; i < N; i++) {
		scanf("%d %d", &x3, &y3);
		now = abs(x3 - x2) + abs(y3 - y2); //a2�� a3���� �Ÿ�
		jump = abs(x1 - x3) + abs(y1 - y3); //a1�� a3���� �Ÿ�

		max_len += now;
		max_jump = max(max_jump, now + pre - jump);
		//������ ���� �� dis(a1,a2) + dis(a2,a3) �� dis(a1,a3)�� ���̸�ŭ �̵��� ����

		x1 = x2, y1 = y2;
		x2 = x3, y2 = y3;
		pre = now;
	}

	max_len -= max_jump; //��ü���̿��� ������ ���� �� �ִ� ���� ū �̵��� ���ش�
	printf("%lld", max_len);
	return 0;
}