#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N;
	while (cin >> N) { //�Է� ���ö����� �ޱ�
		string str = "-";
		while( N-- > 0) { //N�� �ݺ����� ĭ��� ���Ѵ�
			string tmp = str;
			for (int i = 0; i < str.size(); i++)
				tmp += " ";
			str = tmp + str;
		}
		cout << str <<"\n";
	}
	return 0;
}