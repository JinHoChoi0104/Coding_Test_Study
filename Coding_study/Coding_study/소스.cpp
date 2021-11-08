#include <iostream>
#include <map>
#include <string>
using namespace std;

#define ll long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	map<string, string>dict;
	dict["black"] = "0";
	dict["brown"] = "1";
	dict["red"] = "2";
	dict["orange"] = "3";
	dict["yellow"] = "4";
	dict["green"] = "5";
	dict["blue"] = "6";
	dict["violet"] = "7";
	dict["grey"] = "8";
	dict["white"] = "9";
	string str;
	cin >> str;
	string ans = dict[str];
	if (ans == "0")
		ans = "";
	cin >> str;
	ans = ans + dict[str];
	cin >> str;
	int n = stoi(dict[str]);
	int num = stoi(ans);
	if (num == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) 
		ans = ans + "0";

	cout << ans;

	return 0;
}