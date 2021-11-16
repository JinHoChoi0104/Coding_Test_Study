#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, tmp_cnt = 0; //제일 많이 팔린 책의 수 저장
	string str;
	map<string, int>dict;
	for (cin >> T; T-- > 0;) {
		cin >> str; //입력으로 썼다가
		dict[str]++;
	}
	for (auto it = dict.begin(); it != dict.end(); it++) {
		if (tmp_cnt < it->second) {
			str = it -> first; //답 저장하는 걸로 씀
			tmp_cnt = it -> second;
		}
	}
	cout << str;
	return 0;
}