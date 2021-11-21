#include <iostream>
#include <string>
using namespace std;
#define ll long long
string dict[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
string ans_str = "";
ll makeToNum(string str) {
	int index = 0;
	ll ans = 0;
	string tmp;
	while (index < str.size()) {
		char ret = str[index];
		ans *= 10;
		for (int i = 0; i <= 10; i++) {
			if (i == 10)
				return -1;
			if (ret != dict[i][0])
				continue;
			int size = dict[i].size();
			tmp = str.substr(index, size);
			if (tmp == dict[i]) {
				ans_str = ans_str + char(i+48);
				ans += i;
				index += size;
				break;
			}
		}
	}
	return ans;
}
bool calculate(ll &ans, string tmp, char cal) {
	if (cal != '?')
		ans_str = ans_str + cal;
	ll num = makeToNum(tmp);
	if (num == -1) {
		cout << "Madness!";
		return false;
	}	
	if (cal == '-')
		ans -= num;
	else if (cal == 'x')
		ans *= num;
	else if (cal == '/')
		ans /= num;
	else //처음과 더하기 두 가지 경우
		ans += num;
	return true;
}
void printString(ll num) {
	cout <<ans_str<< "=\n";
	if (num == 0) {
		cout << "ZERO";
		return;
	}
	else if (num < 0) {
		cout << "-";
		num *= -1;
	}
	string str = "";
	while (num) {
		str = dict[num%10] + str;
		num /= 10;
	}
	cout << str;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str, tmp = "";
	char cal = '?';
	ll ans = 0;
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == 'x' || str[i] == '/') {
			if (tmp == "") {
				cout << "Madness!";
				return 0;
			}
			if (!calculate(ans, tmp, cal)) 
				return 0;
			tmp = "";
			cal = str[i];
		}
		else
			tmp = tmp + str[i];
	}

	if (!calculate(ans, tmp, cal))
		return 0;
	printString(ans);
	return 0;
}