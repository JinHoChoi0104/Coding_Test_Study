#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(void) {
	int N, num, b, c;
	vector<int>arr; //응시자의 수 저장
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr.push_back(num);
	}
	scanf("%d %d", &b, &c);
	ll sum = N; //총 감독관은 무조건 들어가므로
	while (N--) {
		arr[N] -= b; // 총감독관만큼 빼준다
		if (arr[N] > 0) { //아직 감독 안 받는 응시자가 남아 있다면
			sum += (arr[N] / c);
			if (arr[N] % c != 0) //딱 안 나눠 떨어지는 경우에는
				sum++; //한명 더 추가
		}
	}
	printf("%lld", sum);
	return 0;
}