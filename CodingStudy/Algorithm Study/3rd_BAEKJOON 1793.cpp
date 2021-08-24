#include <iostream>
#include <vector>
using namespace std;

# define MAX_LEN 100000000

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num, index = 0;
	vector<vector<int>> dp(10, vector<int>(251)); //숫자가 너무 커지면 벡터를 이용해 나누어서 저장한다
	vector<int> len(251); //몇 개의 데이터에 나눠서 저장했는지 기억한다
	dp[0][0] = 1, dp[0][1] = 1;
	/*
	if num = 1354  7025 1111
	dp[1][num] = 1354, dp[0][num] = 7025 1111
	*/
	for (int i = 2; i <= 250; i++) {
		num = 0;
		for (int j = 0; j <= index; j++) {
			dp[j][i] = dp[j][i - 1] + dp[j][i - 2] * 2 + num;
			num = 0;
			if (dp[j][i] >= MAX_LEN) { //기준 크기를 넘기면
				num = dp[j][i] / MAX_LEN; //앞으로 넘길 수를 구하고
				dp[j][i] %= MAX_LEN; //뒤에 남길 숫자만 남긴다
				if (j == index) //제일 앞에서 이 일이 일어났다면 데이터를 확장한다
					index++;
			}
		}
		len[i] = index;
	}
	

	while (cin >> num ) { //EOF가 주어질 때 까지
		for (int i = len[num]; i >= 0; i--) {
			if(i == len[num])
				cout << dp[i][num];
			else {
				cout.width(8); // 폭을 8으로 지정
				cout.fill('0'); // 채우는 문자는 '0'
				cout << dp[i][num];
			}
				
		}
		cout <<"\n";
	}

	return 0;
}