#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> edge[10001];
vector<char> v1;
vector<char> v2;
vector<string> tmp1;
vector<string> tmp2;

void get1(string str, int index, int cnt) {
	if (str.size() == cnt) {
		tmp1.push_back(str);
		return;
	}
	if (index == v1.size())
		return;
	for (int i = index; i < v1.size(); i++)
		get1(str + v1[i], i + 1, cnt);
}
void get2(string str, int index, int cnt) {
	if (str.size() == cnt) {
		tmp2.push_back(str);
		return;
	}
	if (index == v2.size())
		return;
	for (int i = index; i < v2.size(); i++)
		get2(str + v2[i], i + 1, cnt);
}
int main() {
	int L, C, num;
	char c;
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			v1.push_back(c);
		else
			v2.push_back(c);
	}

	/* 
	1 <= ����, 2<= ����, ���� + ���� = L
	1 <= L - ����  
	2 < = ���� <= L - 1
	*/
	vector<string> ans;
	for (int i = 2; i < L; i++) {
		// ���� ��: L - i , ���� ��: i
		get1("", 0, L - i); // L-i���� ���� �� �ִ� ���� ����
		get2("", 0, i); // ���� ����
		for (int p = 0; p < tmp1.size(); p++) { //������ ��� ������
			for (int q = 0; q < tmp2.size(); q++) { //������ ��� ������ 
				string str = tmp1[p] + tmp2[q];  //�� ���ĺ���
				vector<char>tmp; 
				for (int k = 0; k < str.size(); k++)
					tmp.push_back(str[k]);
				sort(tmp.begin(), tmp.end());
				str = "";
				for (int k = 0; k < tmp.size(); k++)
					str = str + tmp[k];
				ans.push_back(str); //string�� ���ĺ��� ������ ���信 ����
			}
		}
		tmp1.clear(), tmp2.clear();
	}
	sort(ans.begin(), ans.end()); //���� string���� ���ĺ������� �����Ѵ�
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it <<"\n";
	return 0;
}