#include <iostream>
#include <vector>

using namespace std;

#define DIV 998244353

int main(void) {
	int N, num;
	scanf("%d", &N);

	vector<int>arr(N); //A의 값들 저장
	vector<long long>dp(N, 1); //overflow 방지용 long long으로 선언
	/*
	가정) arr[1] 과 arr[2] 보다 arr[3가] 클 경우
	dp[1]은 arr[1]을 무조건 포함한다, 그러나 arr[2]는 포함하지 않는다
	dp[2]는 arr[2]를 무조건 포함한다
	즉, dp[1]과 dp[2]는 서로 겹치는 경우가 없는 독립 집합이다

	이것을 이용해 dp[3]은 단순히 dp[1]의 모든 경우에 arr[3]을 뒤에 붙이고, 마찬가지로 dp[2]에도 arr[3]을 붙여준다.
	이 두 가지의 경우도 앞에서와 같이 독립집합이다
	마지막으로 arr[3] 혼자 있는 경우도 있으니, dp[3]에 1을 더해준다.
	*/
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i]) //앞에 있는 수보다 더 크다면 그 수 다음에 arr[i]를 붙힐 수 있다.
				dp[i] += dp[j]; //이 과정에서 int 범위를 초과할 경우 overflow 발생한다
		dp[i] %= DIV;
	}

	for (int i = 0; i < N; i++)
		printf("%lld ", dp[i]);

	return 0;
}