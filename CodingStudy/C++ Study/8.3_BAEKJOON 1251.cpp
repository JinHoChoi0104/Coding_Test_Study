#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	int index = str.at(0),len = str.length();
	string ans = "z";
	for (int i = 1; i < len; i++) 
		ans += "z";
	queue<int>q1;
	q1.push(0);
	for (int i = 1; i < len - 2; i++) { //���� ���� �� ���ĺ��� �����ϰ�, ���� ���� ���ĺ��� ã�´�
		if (index > str.at(i)) {
			while(!q1.empty())
				q1.pop();
			q1.push(i);
			index = str.at(i);
		}
		else if (index == str.at(i)) //���� ���� ���� �������� ���
			q1.push(i);
	}
	while (!q1.empty()) {
		int cut1 = q1.front()+1;
		q1.pop();
		string str1 = str.substr(0, cut1); //cut1�� �����Ͽ� ���� �ڸ���
		reverse(str1.begin(), str1.end()); //�����´�

		//2��° �ڸ� �� Ž��
		queue <int> q2;
		q2.push(cut1);
		index = str.at(cut1 );
		for (int i = cut1 + 1; i < len - 1; i++) { //���� ���� ���ĺ� �ϳ��� �����ϰ�, ���� ���� ���ĺ��� ã�´�
			if (index > str.at(i)) {
				while (!q2.empty())
					q2.pop();
				q2.push(i);
				index = str.at(i);
			}
			else if (index == str.at(i)) //���� ���� ���� �������� ���
				q2.push(i);
		}

		while (!q2.empty()) {
			int cut2 = q2.front()+1;
			q2.pop();
			string str2 = str.substr(cut1, cut2 - cut1); //cut1 �ڿ������� cut2���� �ڸ���
			string str3 = str.substr(cut2); //������
			reverse(str2.begin(), str2.end()); //�����´�
			reverse(str3.begin(), str3.end());

			string tmp = str1; //3��Ʈ ��ģ��
			tmp += str2, tmp += str3;

			if (ans > tmp) //���� ���� ���ڿ��� ã�´�
				ans = tmp;
		}
	}
	cout << ans;
	return 0;
}