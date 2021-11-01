#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str, tmp;
	cin >> str;
	int T, cnt = 0;
	for (cin >> T; T-- > 0;) {
		cin >> tmp;
		tmp = tmp + tmp; //첫번재 문자와 뒤 문자를 이어준다
		/*
		find 함수는 찾고자 하는 문자열의 주소를 반환한다.
		만약 없을 경우에는 string::npos를 반환한다.
		파라미터를 두개 줄 경우에는 
		(찾고자 하는 문자열, 탐색을 시작하는 주소값)
		*/
		if (tmp.find(str) != string::npos) //존재한다면
			cnt++; //카운트
	}
	cout << cnt;
	return 0;
}