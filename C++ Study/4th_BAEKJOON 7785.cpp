#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N;
	set<string, greater<string>> s; //�������� ���� ����
	string a, b;
	for (cin >> N; N-- > 0;) {
		cin >> a >> b;
		if (b == "enter")
			s.insert(a);
		else //�����°Ÿ� ������ ����
			s.erase(a);
	}
	for (auto it = s.begin(); it != s.end(); it++) //���
		cout << *it << "\n";
	return 0;
}