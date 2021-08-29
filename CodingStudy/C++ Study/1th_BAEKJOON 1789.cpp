#include <iostream>
using namespace std;
/*
자연수 N이 커질려면 서로 다른 N개의 자연수가 최대한 작아야 된다
즉 S = 1 + 2 + 3 + ... + arr[N-1] + arr[N]
S를 이루는 N개의 자연수 중 뒤에 마지막 수를 제외하고는 공차가 1인 등차수열을 이루게 한다.
마지막수는 S를 이루기 위해 필요한 수로 채운다
ex)
8 = 1 + 2 + 5
15 = 1 + 2 + 3 + 4 + 5
17 = 1 + 2 + 3 + 4 + 7
*/

int main() {
	long long S;
	scanf("%lld", &S);
	for (int i = 1; ; i++) {
		if (S - i >= 0) //S에서 1부터 차례 차례 빼준다
			S -= i;
		else { //만약 남은 S보다 i가 크면 stop
			printf("%d", i - 1);
			return 0;
		}
	}
}
/*
else의 예시
S = 17일 경우
1부터 5까지 빼주면 S = 2이고 i = 6이다
이 때 마지막으로 빼준 수인 i-1 = 5에다가 남은 S를 더해주면
S를 만들 수 있다
그러므로 출력을 i - 1이다
*/