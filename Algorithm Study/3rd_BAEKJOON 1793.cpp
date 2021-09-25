#include <iostream>
#include <vector>
using namespace std;

# define MAX_LEN 100000000

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num, index = 0;
	vector<vector<int>> dp(10, vector<int>(251)); //���ڰ� �ʹ� Ŀ���� ���͸� �̿��� ����� �����Ѵ�
	vector<int> len(251); //�� ���� �����Ϳ� ������ �����ߴ��� ����Ѵ�
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
			if (dp[j][i] >= MAX_LEN) { //���� ũ�⸦ �ѱ��
				num = dp[j][i] / MAX_LEN; //������ �ѱ� ���� ���ϰ�
				dp[j][i] %= MAX_LEN; //�ڿ� ���� ���ڸ� �����
				if (j == index) //���� �տ��� �� ���� �Ͼ�ٸ� �����͸� Ȯ���Ѵ�
					index++;
			}
		}
		len[i] = index;
	}
	

	while (cin >> num ) { //EOF�� �־��� �� ����
		for (int i = len[num]; i >= 0; i--) {
			if(i == len[num])
				cout << dp[i][num];
			else {
				cout.width(8); // ���� 8���� ����
				cout.fill('0'); // ä��� ���ڴ� '0'
				cout << dp[i][num];
			}
				
		}
		cout <<"\n";
	}

	return 0;
}