#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	int T, cnt = 0;
	stack<char> s;
	for (cin >> T; T-- > 0;) {
		cin >> str;
		bool isGood = true;
		for (int i = 0; i < str.size(); i++) {
			char tmp = str[i];
			if (s.empty())  //비어 있다면 쌓아준다
				s.push(tmp);
			else { //스텍에 단어가 있다면
				if (s.top() != tmp)  //가장 최상단의 단어가 다르다면
					s.push(tmp);
				else //단어가 같다면
					s.pop();
			}
		}

		if (s.empty()) //스텍이 비어있다 = 모두 짝을 찾았다
			cnt++;
		else {
			while (!s.empty())
				s.pop();
		}
	}
	cout << cnt;
	return 0;
}