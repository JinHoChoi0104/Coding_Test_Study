#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num, pre=0, max_len = 1, len = 0;
	bool upward = true;
	for (cin >> T; T-- > 0; ) {
		cin >> num;
		if (pre < num) { //���� ����
			if (upward) //���� ���� ���̿���
				len++;
			else { //���� ���� ���̿����Ƿ� ��� ��
				max_len = max_len > len ? max_len : len;
				upward = true; //�ٽ� �ö� �غ�
				len = 2; //�������� ���ݲ� ���ļ� ���� 2
			}
		}
		else if (pre > num) {
			if (upward) //�ö󰡴� ���̿����� ���� ��������
				upward = false;			
			len++;
		}
		else { //������ ���̰� ���ٸ�
			max_len = max_len > len ? max_len : len;
			upward = true; //�ٽ� �ö� �غ�
			len = 1; //�������� ���� �� �ϰ� �̹����� ����
		}
		pre = num;
	}
	max_len = max_len > len ? max_len : len;
	cout << max_len;
	return 0;
}