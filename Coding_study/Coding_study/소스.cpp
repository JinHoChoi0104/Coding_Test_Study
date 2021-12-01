#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str1, str2;
	getline(cin, str1);
	cin >>  str2;
	int len = str2.size();
	for (int i = 0; i < str1.size(); i++) {
		if(str1[i] == ' '){
			cout << " ";
			continue;
		}
		int tmp = str1[i] - str2[i % len];
		if (tmp > 26)
			tmp -= 26;
		else if (tmp <= 0)
			tmp += 26;
		cout << char(tmp + 'a' - 1);
	}
	
	return 0;
}	