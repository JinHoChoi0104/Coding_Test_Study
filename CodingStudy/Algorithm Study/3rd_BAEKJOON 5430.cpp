#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int T, N, num;
	string str,str2;
	char c;

	for (cin >> T; T > 0; T--) { //���� �Է¹ޱ�
		cin >> str >> N;
		deque <int > dq;
		for (int i = 0; i < N; i++) {
			cin >> c >> num; //���� ���� ������ ���� �Է� �ޱ�
			dq.push_back(num);
		}
		cin >> str2; //������ ���� ] �Է� �ޱ�
		//���ڰ� ��� �Է��� []�� ��츦 ���� string���� �Է¹ޱ�
		
		int len = str.length(), front = 1; //front �� ���������ִ��� ���� Ȯ�� ��
		bool iserror = false; // �������� Ȯ�ο�
		for (int i = 0; i < len; i++) {
			if (str.at(i) == 'R')
				front *= -1;
			else {
				if (dq.empty()) {
					iserror = true;
					break;
				}
				if (front == 1)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (iserror)
			cout << "error\n";
		else { //������ �ƴϸ� ���
			cout << "[";
			while (!dq.empty()) {
				if (front == 1) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				else {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}