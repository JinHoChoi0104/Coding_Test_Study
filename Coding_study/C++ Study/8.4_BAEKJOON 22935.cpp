#include <iostream>
using namespace std;

/* 
1 <2 ~ 14> 15 <16 ~ 28> 29 <30 ~ 42> 43 <44 ~ 56>
1���� 28
29���� 56 �̷������� �ֱⰡ 28�� ���·� �ݺ� �ȴ�.
28�� ������ ������ ������ ���� �̿��� �� ��°�� ������ �ľ��Ѵ�.
�� �� ���������� 28�� ������ �������� 0�� �Ϳ� �����ؾ��Ѵ�.
�� ��������
1 ~ 28�� �ƴ϶� 1 ~ 27,0 �� ���´�
*/ 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num;
	string str[30];
	for (int i = 1; i < 16; i++) {
		string tmp;
		int cnt = 0;
		num = i;
		while (num) {
			if (num % 2 == 0)
				tmp = "V" + tmp;
			else
				tmp = "����" + tmp;
			num /= 2, cnt++;
		} //2�������� ȯ�� �ϸ鼭 �ٷ� ����� ��ȯ �� ����
		while (cnt++ < 4) //������ �� ������ V�� ä���
			tmp = "V" + tmp;
		str[i] = tmp;
	}
	for (int i = 16; i < 30; i++) 
		str[i] = str[30 - i];
	
	str[0] = str[28]; //28��°�� ���� �������� 0�̹Ƿ�
	
	for (cin >> T; T-- > 0; ) {
		cin >> num;
		cout << str[num % 28] <<"\n";
	}
	return 0;
}