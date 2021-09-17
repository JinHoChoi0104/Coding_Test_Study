#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int t, pi[3] = {0,0,0};
	string str;
	for (cin >> t; t-- > 0;) {
		cin >> str;
		if (str == "1/4")
			pi[0]++;
		else if (str == "1/2")
			pi[1]++;
		else
			pi[2]++;

	}
	int cnt = pi[1] / 2; //�� ���� ���� ī��Ʈ 
	pi[1] %= 2;  //������ ���ų� �ϳ� ���´�

	if (pi[2] >= pi[0]) { // 3/4 ������ �� ���� ��
		cnt += pi[2]; // 3/4 ������ŭ ��Ű�� 1/4������ �װ��� ���� ������ �ȴ� 
		cnt += pi[1];
	}
	else { // 1/4������ �� ���ų� ���� ��
		cnt += pi[2];
		pi[0] -= pi[2]; //���� 1/4����
		if (pi[1] == 0) { //���� 1/2������ ����
			cnt += pi[0] / 4;
			if (pi[0] % 4 != 0)
				cnt++;
		}
		else {
			cnt++; // �켱 1/2���� ī��Ʈ 
			if (pi[0] > 2) { // 1/4������ 2�� �ʰ� ������ �װ͵� ī��Ʈ
				pi[0] -= 2;
				cnt += pi[0] / 4;
				if (pi[0] % 4 != 0)
					cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}