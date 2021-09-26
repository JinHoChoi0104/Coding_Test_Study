#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str, ans = "";
	getline(cin, str);

	int index = 0, len = str.size();
	str = str + " ";

	while (index < len) { //�±�
		if (str[index] == '<') {
			while (str[index] != '>') 
				cout << str[index++];
			cout << str[index++];
		}
		else { //�ܾ�
			stack<char>tmp; //�ܾ� �ӽ� ����
			while (str[index] != ' ' && str[index] != '<') 
				tmp.push( str[index++]);
			while (!tmp.empty()) { //����� ��� �ȴ�
				cout << tmp.top();
				tmp.pop();
			}
			//���� ���ڰ� �±װ� �ƴϰ�, �� �ܾ �ƴϸ� ���� �ٿ��ش�
			if (str[index] == ' ' && index != len)
				cout << str[index++];
			else if(str[index] == ' ')
				index++;
		}
	}

	return 0;
}