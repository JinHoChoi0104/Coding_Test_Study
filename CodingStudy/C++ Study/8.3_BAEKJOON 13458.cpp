#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(void) {
	int N, num, b, c;
	vector<int>arr; //�������� �� ����
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr.push_back(num);
	}
	scanf("%d %d", &b, &c);
	ll sum = N; //�� �������� ������ ���Ƿ�
	while (N--) {
		arr[N] -= b; // �Ѱ�������ŭ ���ش�
		if (arr[N] > 0) { //���� ���� �� �޴� �����ڰ� ���� �ִٸ�
			sum += (arr[N] / c);
			if (arr[N] % c != 0) //�� �� ���� �������� ��쿡��
				sum++; //�Ѹ� �� �߰�
		}
	}
	printf("%lld", sum);
	return 0;
}