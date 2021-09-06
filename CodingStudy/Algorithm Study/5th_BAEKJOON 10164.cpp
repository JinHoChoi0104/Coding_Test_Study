#include <iostream>
#include <vector>
using namespace std;

#define ll long long
/*
(N + M)! / N! / M!

  (N + M)!
  --------
   N! * M!

= (N+M) * (N+M-1) * (N+M-2) *... M+1 / N!
*/
ll getWay(ll N, ll M) //조합계산
{
	ll ans = 1, div = 1;
	for (int i = M + 1; i <= (N + M); i++) 
		ans *= i;
	for (int i = 2; i <= N; i++)
		div *= i;
	return ans / div;
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	if (K == 0) { //거쳐야 되는 곳 없을 경우
		printf("%lld", getWay(N-1, M-1));
		return 0;
	}

	int x = K/M, y = K%M; //거쳐야되는 곳의 좌표 계산
	if (y == 0)
		y = M;
	else
		x++;

	printf("%lld", getWay(x - 1, y - 1) * getWay(N - x, M - y));
	
	return 0;
}