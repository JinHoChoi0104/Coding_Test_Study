#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(vector<int> &num) { //ȸ�� ���� �Ǵ�
	int i = 0, j = num.size() - 1;
	while (i < j) {
		if(num[i++]!=num[j--])
			return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num;
	for (cin >> T; T-- > 0;) {
		cin >> num;
		bool is_Palin = false;
		int i = 1;
		while( i++ < 64 && !is_Palin) {
			//���� ��ȯ
			int tmp = num;
			vector<int> ans;
			while (tmp > 0) {
				ans.push_back(tmp%i);
				tmp /= i;
			}
			is_Palin = checkPalindrome(ans);;
			if (is_Palin) //ȸ���̸� �극��ũ
				break;
		}
		if (is_Palin)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}