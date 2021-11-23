#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int num1 = stoi(str1), num2 = stoi(str2);
	string ans = to_string(num1 + num2);
	reverse(ans.begin(), ans.end());
	int ans_num = stoi(ans);
	cout << ans_num;
	return 0;
}