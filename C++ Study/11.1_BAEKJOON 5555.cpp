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
		tmp = tmp + tmp; //ù���� ���ڿ� �� ���ڸ� �̾��ش�
		/*
		find �Լ��� ã���� �ϴ� ���ڿ��� �ּҸ� ��ȯ�Ѵ�.
		���� ���� ��쿡�� string::npos�� ��ȯ�Ѵ�.
		�Ķ���͸� �ΰ� �� ��쿡�� 
		(ã���� �ϴ� ���ڿ�, Ž���� �����ϴ� �ּҰ�)
		*/
		if (tmp.find(str) != string::npos) //�����Ѵٸ�
			cnt++; //ī��Ʈ
	}
	cout << cnt;
	return 0;
}