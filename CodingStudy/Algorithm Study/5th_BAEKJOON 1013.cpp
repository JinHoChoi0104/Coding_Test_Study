#include <iostream>

using namespace std;
/*
regex��°� �ִ�!!!
�������ִ��� �Ǻ� �� �� ����!
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	int T;
	for (cin >> T; T-- > 0;) {
		cin >> str;
		str += '2';
		bool isP = true;
		int i = 0;
		while( i < str.size() - 1) {
			if (str.at(i++) == '0') { // 01�� ���
				if (str.at(i++) != '1') {
					isP = false;
					break;
				}
			}
			else { //1001�� ���
				if (str.at(i++) != '0') { //0�� 2���� ������ �־����
					isP = false;
					break;
				}
				if (str.at(i++) != '0') {
					isP = false;
					break;
				}
				while (str.at(i) == '0') 
					i++;	
				//1000111 '1' 1001 1 01 1101
				if (str.at(i++) != '1') { //1�� 1���� ������ �־����
					isP = false;
					break;
				}
				int k = 0;
				while (str.at(i) == '1') {
					i++;
					k++;
				}
				if (k == 0) //�ݺ��Ǵ� 1�� ���� ��� pass
					continue;
				
				if (str.at(i++) == '2') //�ݺ��Ǵ� 1�� ���� �� ���� ���
					break;
				//�ݺ��Ǵ� 1�� ���� �� 0�� ���� ��� ex) 100111110
				//�� ���� ���ڰ�
				if (str.at(i) == '0') //00�̸� 1001�ϼ��� ������ ������ ���� üŷ 
					i -= 2;
				else if (str.at(i) == '1') //01�̸� �� �ϳ��� ����
					i++;
				else { //02�̸� ���� �� ���� ����
					isP = false;
					break;
				}
			}
		}
		if (isP)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}