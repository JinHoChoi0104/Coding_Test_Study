#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> dp(500, vector<int>(500, -1)); 
// dp[i][j] = i에서 j까지의 파일을 합치는데 필요한 최소 비용
vector<int> arr(500);
// 파일 크기 저장

int merging(int l, int r){ //분할 정복!
	int& ret = dp[l][r];
	if (ret != -1) //값을 이미 구한 경우
		return ret;

	ret = 0;
	for (int i = l; i <= r; i++) //l에서 r까지 파일크기 합
		ret += arr[i];
	int num = 2147483647; //int 최대값
	for (int i = l; i < r; i++) 
		num = min(num, merging(l, i) + merging(i + 1, r)); // 파일을 합칠 수 있는 모든 경우의 수들 중 최소를 찾는다
	
	ret += num; 
	//l에서 r까지의 파일을 합치는데 필요한 최소 비용 = l에서 r까지 파일크기 합 + 이전 단계의 파일 2개를 만드는 데 필요합 비용의 합
	return ret;
}


int main() {
	//freopen("input.txt", "r", stdin);
	int T, num;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				dp[i][j] = -1;
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			dp[i][i] = 0; //파일 1개는 합치는 비용이 0이다
		}

		printf("%d\n", merging(0, N - 1));
	}
}