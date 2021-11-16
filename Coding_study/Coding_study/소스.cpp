#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, tmp_cnt=0;
	string str;
	map<string, int>dict;
	for (cin >> T; T-- > 0;) {
		cin >> str;
		dict[str]++;
	}
	for (auto it = dict.begin(); it != dict.end(); it++) {
		if (tmp_cnt < it->second) {
			str = it -> first;
			tmp_cnt = it -> second;
		}
	}
	cout << str;
	return 0;
}