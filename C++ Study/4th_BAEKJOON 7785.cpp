#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N;
	set<string, greater<string>> s; //내림차순 정렬 저장
	string a, b;
	for (cin >> N; N-- > 0;) {
		cin >> a >> b;
		if (b == "enter")
			s.insert(a);
		else //나가는거면 데이터 삭제
			s.erase(a);
	}
	for (auto it = s.begin(); it != s.end(); it++) //출력
		cout << *it << "\n";
	return 0;
}