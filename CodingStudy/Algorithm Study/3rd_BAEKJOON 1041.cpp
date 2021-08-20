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
	A B C D E F 순으로 입력이 들어온다
	B 와 F의 자리를 바꾸면
	(A F) (C D) (E B)
	A F C D 는 한 줄을 이루게 되며, () 안에 있는 수들은 서로 마주보는 위치로 서로 만날 수가 없다
	*/
	
	int tmp = arr[5]; //B와 F 자리 바꾼다.
	arr[5] = arr[1];
	arr[1] = tmp;

	if (n == 1) { // n = 1 인 경우는 예외 처리
		int max_num=0;
		for (int i = 0; i < 6; i++) 
			max_num = max(max_num, arr[i]);
		printf("%lld", total_sum - max_num);
		return 0;
	}
	
	/*
	n >= 2 인 경우
	k 는 몇개의 면이 노출 되어있는지를 나타낸다고 할 때,
	sum[k] 는 k개의 면이 노출 될 때 주사위가 가지는 k면의 최소합
	num[k] 는 k개의 면이 노출 되는 주사위가 몇개인지 나타낸다.

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
	F 와 C를 바꾸고 난 후의 arr[0~3] = A C F D인데 이는 주사위에서 한 줄로 띠처럼 연속적으로 배치된 형태다.
	연속 된 두 수의 합들 중 최소값을 구하고 남은 두 수 B 와 E의 합 중 최소를 구한다.
	이 두 수의 합이 sum[3]이다.
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