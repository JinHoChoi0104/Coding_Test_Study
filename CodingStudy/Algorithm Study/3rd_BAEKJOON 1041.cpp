#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main(void) {
	ll n;
	int total_sum = 0, index = 0, arr[6];
	scanf("%lld", &n);
	
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
		total_sum += arr[i];
	} 
	/*
	A B C D E F ������ �Է��� ���´�
	B �� F�� �ڸ��� �ٲٸ�
	(A F) (C D) (E B)
	A F C D �� �� ���� �̷�� �Ǹ�, () �ȿ� �ִ� ������ ���� ���ֺ��� ��ġ�� ���� ���� ���� ����
	*/
	
	int tmp = arr[5]; //B�� F �ڸ� �ٲ۴�.
	arr[5] = arr[1];
	arr[1] = tmp;

	if (n == 1) { // n = 1 �� ���� ���� ó��
		int max_num=0;
		for (int i = 0; i < 6; i++) 
			max_num = max(max_num, arr[i]);
		printf("%lld", total_sum - max_num);
		return 0;
	}
	
	/*
	n >= 2 �� ���
	k �� ��� ���� ���� �Ǿ��ִ����� ��Ÿ���ٰ� �� ��,
	sum[k] �� k���� ���� ���� �� �� �ֻ����� ������ k���� �ּ���
	num[k] �� k���� ���� ���� �Ǵ� �ֻ����� ����� ��Ÿ����.

	num[3] = 4
	num[2] = 8 * n - 12
	num[1] = 5 * n ^ 2 - 16 * n + 12
	*/

	int sum[4];
	sum[1] = total_sum;
	for (int i = 0; i < 6; i++) 
		if (sum[1] > arr[i]) {
			sum[1] = arr[i];
			index = i;
		}

	sum[2] = total_sum;
	for (int i = 0; i < 6; i++) {
		if (index % 2 ==1) // 1 , 3 , 5
			if(index - i == 1 )
				continue;
		if (index % 2 == 0) // 0 , 2, 4
			if (index - i == -1)
				continue;
		if( index == i)
			continue;
		sum[2] = min(sum[2], sum[1] + arr[i]);
	}

	/*
	F �� C�� �ٲٰ� �� ���� arr[0~3] = A C F D�ε� �̴� �ֻ������� �� �ٷ� ��ó�� ���������� ��ġ�� ���´�.
	���� �� �� ���� �յ� �� �ּҰ��� ���ϰ� ���� �� �� B �� E�� �� �� �ּҸ� ���Ѵ�.
	�� �� ���� ���� sum[3]�̴�.
	*/
	sum[3] = arr[0] + arr[3];
	tmp = arr[2];
	arr[2] = arr[1];
	arr[1] = tmp;
	for (int i = 0; i < 3; i++) 
		sum[3] = min(sum[3], arr[i] + arr[i + 1]);
	if (arr[4] > arr[5])
		sum[3] += arr[5];
	else
		sum[3] += arr[4];
	//cout << sum[1] << " " << sum[2] << " " << sum[3] << endl;
	long long ans = 0;
	ans += (5 * n * n - 16 * n + 12) * sum[1];
	ans += (8 * n - 12) * sum[2];
	ans += 4 * sum[3];
	printf("%lld", ans);
	return 0;
}