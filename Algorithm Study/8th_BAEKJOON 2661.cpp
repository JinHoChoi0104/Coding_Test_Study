#include <iostream>
#include <string>
using namespace std;

bool gotAnswer = false;
int N;
string ans;

/*
N ������ ���� ������ ���� ��
�ڿ� �� ���ڸ� ������
N + 1 ������ ���ο� ������ ���� ������ �Ǳ� ���ؼ���
������ ���ڸ� �����Ͽ� ������ ���ܾ��Ѵ�

�̸� �̿��� ���� 1���� �����ؼ� ��ǥ ���̱��� �ϳ��� 
�÷����� ���ۼ��� ���θ� Ȯ���Ѵ�.
*/

bool isBad(string str) { //���� �������� Ȯ��
	int len = str.size(); 
	for (int i = 1; i <= len / 2; i++) { //������ ������ ���̴� ��ü������ ��
		if (str.substr(len - i, i) == str.substr(len - i * 2, i))
			return true;
	}
	return false;
}

void makeNum(string str) { //������ ���� ������ �����
	int len = str.size();
	if (len == N) { //��ǥ ���̸� ���߰� ���� ��ȯ
		gotAnswer = true;
		ans = str;
		return;
	}
	for (int i = 1; i <= 3; i++) { //��͸� ���� DFS���� ���ϹǷ� ������������ ���� �� �ִ�
		string tmp = str + to_string(i);
		if (isBad(tmp))
			continue;
		if (gotAnswer) //�� �������� STOP
			break;
		makeNum(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	string tmp = "1";
	makeNum(tmp);
	cout << ans;
	return 0;
}