#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int i, n = citations.size();
	sort(citations.begin(), citations.end()); //�켱 ���� �Ѵ�
	for (i = 0; i <= citations[n - 1]; i++) { //�ִ� ���� �ο���� ���� ���� �ο�� ���� ���̴�
		int index = lower_bound(citations.begin(), citations.end(), i) - citations.begin();
		//index�� i�̻� ���� �� ù ��° ���� �ε����̴�
		//�տ� ����, �� ������ ������ i�� �̸����� �ο�����Ƿ�, h�� ���� �ο��� ����
		if (n - index >= i) // n - index �� i�� �̻� �ο�� ���� ��
			continue; // i�� �̻� �ο�� ���� ���� i �� �̻��̸� �н�
		break; //�ƴϸ� �극��ũ
	}
	return i - 1; //�ƴ� �� �������ϱ� -1 ���ְ� ����
}