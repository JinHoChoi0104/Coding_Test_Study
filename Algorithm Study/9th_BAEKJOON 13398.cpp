#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[100000][2];//제외한게 없는 경우, 제외한 경우의 최댓값
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num, N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	N = arr.size();
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	int ans = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		//앞에 것을 가져오기 vs 가져오지 않기
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		//i번째를 지우기 vs i번째 지우지 않기
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans;
	return 0;
}