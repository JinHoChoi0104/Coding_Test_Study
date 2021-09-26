#include <iostream>
#include <string>
using namespace std;
#define ll long long 

string dp[101][101];
string strPlus(string a, string b) {
	string ans = "";
	int len1 = a.size(), len2 = b.size();
	if (len1 < len2) {
		string tmp = a;
		a = b, b = tmp;
		int tmp2 = len1;
		len1 = len2, len2 = tmp2;
	}
	len1--, len2--;

	int up = 0;
	while (len1 >= 0) { // len1 >= len2
		int tmp = a[len1--] - '0', tmp2;
		if (len2 == -1)
			tmp2 = 0;
		else
			tmp2 = b[len2--] - '0';

		int sum = tmp + tmp2 + up;
		up = 0;
		if (sum > 9) 
			sum -= 10, up = 1;
			
		ans = to_string(sum) + ans;
	}
	if (up == 1) 
		ans = "1" + ans;
	
	return ans;
}
string getCombination(int N, int M) {
	string&ret = dp[N][M];
	if (ret != "-1") 
		return ret;

	if (M == 1)
		return ret = to_string(N);
	else if (N == M)
		return ret = "1";
	else
		return ret = strPlus(getCombination(N - 1, M), getCombination(N - 1, M - 1));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = "-1";
	/*
	조합! mCn 구하면 된다
	mCn = m-1 C n + m-1 C n-1
	*/

	cout << getCombination(N, M);
	return 0;
}