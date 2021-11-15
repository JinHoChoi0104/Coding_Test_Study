#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(vector<int> &num) { //회문 여부 판단
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
			//진법 변환
			int tmp = num;
			vector<int> ans;
			while (tmp > 0) {
				ans.push_back(tmp%i);
				tmp /= i;
			}
			is_Palin = checkPalindrome(ans);;
			if (is_Palin) //회문이면 브레이크
				break;
		}
		if (is_Palin)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}