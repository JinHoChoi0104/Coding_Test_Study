#include <iostream>
#include <algorithm>
using namespace std;

int N;
string target;
void changeNUM(string& num, int index) {
	for (int i = index - 1; i <= index + 1; i++) {
		if (i == N || i == -1) //���� ����� �н�
			continue;
		if (num[i] == '0')
			num[i] = '1';
		else
			num[i] = '0';
	}
}
int LED(string str) {
	int cnt1 = 1, cnt2 = 0, ans = -1;
	string tmp1 = str, tmp2 = str;
	// ù��° ����ġ�� Ŭ���� ���
	changeNUM(tmp1, 0);
	for (int i = 1; i < N; i++) {
		if (target[i - 1] != tmp1[i - 1]) {
			changeNUM(tmp1, i);
			cnt1++;
		}
	}
	if (tmp1 == target) //��ǥ �������� üũ
		ans = cnt1;
	// ����ġ�� Ŭ������ ���� ���
	for (int i = 1; i < N; i++) {
		if (target[i - 1] != tmp2[i - 1]) {
			changeNUM(tmp2, i);
			cnt2++;
		}
	}
	if (tmp2 == target)
		ans = max(ans, cnt2);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	string str;
	cin >> str >> target;
	if (str == target) { //�̹� ��ġ�ϴ� ���
		cout << 0;
		return 0;
	}

	cout << LED(str);
	return 0;
}