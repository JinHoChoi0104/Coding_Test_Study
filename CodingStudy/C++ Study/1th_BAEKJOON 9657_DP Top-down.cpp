#include <iostream>
#include <vector>
using namespace std;
/*
만약 창영이가 돌이 처음에 K개 있을 때 무조건 이길 수 있다고 할 때.
상근이는 돌이 K+1, K+3, K+4개 있을 때 무조건 이길 수 있다.

창영이가 돌이 처음에 K개가 있을 때 이긴다는 것은 상근이는 돌이 K개 있으면
진다는 뜻이다. 즉 자신의 차례에 돌이 K개가 있으면 진다는 뜻이다.

돌이 처음에 K+1, K+3, K+4개가 있으면, 1, 3, 4개의 돌을 가져와 돌을
K개 남긴다. 이러면 창영이 차례에 돌이 K개가 남아있고, 창영이가 진다는 뜻이다.


이를 이용해 1에서부터 1000까지 차례 차례로 창영이가 이기는 경우에 +1 +3 +4는
상근이가 이긴다를 기록해준다.
이 때 기록이 안 된 경우는 창영이가 이기는 경우이다. 현재 상근이가 이길 수 있는
경우만 기록하고 있기 때문에 나머지의 경우는 창영이가 이기는 경우이다.
*/
vector<int>dp(1001);
int stone(int index) {
	int &ret = dp[index];
	if (dp[index] != 0) 
		return ret;
	
	if (stone(index - 1) == 1 && stone(index - 3) == 1 && stone(index - 4) == 1)
		ret = 2;
	else
		ret = 1;
	return ret;
}

int main() {
	int N, K, num;
	scanf("%d", &N);
	
	dp[1] = 1, dp[2] = 2, dp[3] = 1, dp[4] = 1;
	if (stone(N) == 1)
		printf("SK");
	else
		printf("CY");
	return 0;
}