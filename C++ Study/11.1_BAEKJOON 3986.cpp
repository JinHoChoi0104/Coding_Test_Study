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
			if (s.empty())  //��� �ִٸ� �׾��ش�
				s.push(tmp);
			else { //���ؿ� �ܾ �ִٸ�
				if (s.top() != tmp)  //���� �ֻ���� �ܾ �ٸ��ٸ�
					s.push(tmp);
				else //�ܾ ���ٸ�
					s.pop();
			}
		}

		if (s.empty()) //������ ����ִ� = ��� ¦�� ã�Ҵ�
			cnt++;
		else {
			while (!s.empty())
				s.pop();
		}
	}
	cout << cnt;
	return 0;
}