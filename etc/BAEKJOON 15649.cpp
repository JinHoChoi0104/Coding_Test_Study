#include <iostream>
using namespace std;

/*
��Ʈ��ŷ (Backtracking) �˰���
������ ��� ����� Ž���Ѵ�
*/

int Factorial(int num) {
	if (num == 0)
		num = 1;
	for (int i = num - 1; i > 0; i--)
		num *= i;
	return num;
}

int main() {
	int n, m;
	cin >> n >> m;
	int* arr = new int[m];
	bool* index = new bool[n + 1];

	for (int i = 0; i < n + 1; i++) {
		index[i] = true;
	}
	for (int i = 0; i < m; i++) {
		arr[i] = i + 1;
		cout << arr[i] << " ";
		index[i + 1] = false;
	}
	cout << "\n";

	int cnt = 1;
	int lim = Factorial(n) / Factorial(n - m);
	int rot, pos;

	while (lim > cnt) {
		rot = 0; //���ؿ��� �� ū ���� ã�Ҵ��� ����
		pos = 0; //�ٲ� ��ġ
		for (int i = m - 1; i > -1; i--) { // <------ Ž��
			for (int j = arr[i]; j < n; j++) {
				if (index[j + 1] == true) { //���ؿ� �� ū ���� �ִ�
					index[arr[i]] = true; // i�� �ִ°� ��������
					arr[i] = j + 1; //�� ū ���� ���ؿ��� i�ڸ���
					index[j + 1] = false; // index �������ֱ�
					rot = 1;
					pos = i; //��� ��ġ ��ȯ ������ ����
					i = -1;
					break;
				}
			}

			if (rot == 0) { // ���ؿ� �� ū ���� ����		
				for (int j = m - 1; j > i; j--) {  // <---- ���� Ž��
					if (arr[i] < arr[j]) {// �� �ڿ� ������ ū���� �ִ��� ����
						//�������� �ִٸ� �����ɷ� �ٵ� ������ �ڿ� �ְ���?
						index[arr[i]] = true; // i�� �ִ°� ��������
						arr[i] = arr[j]; //�� ū ���� ���ؿ��� i�ڸ���
						arr[j] = 0; // ���� �ڸ��� �ִ��� 0����
						pos = i;
						i = -1;
						break;
					}
				}
			}
			if (i == -1) { //�տ��� ��ȯ�� �Ͼ�ٸ�
				for (int j = pos + 1; j < m; j++) { // �� �ڿ� ���� �� ��������
					index[arr[j]] = true;
					arr[j] = 0;
				}
				for (int p = pos + 1; p < m; p++) { // �� �ڿ� ���ؿ��� �ٱ� ��������
					for (int q = 1; q < n + 1; q++) {
						if (index[q] == true) {
							arr[p] = q;
							index[q] = false;
							break;
						}
					}
				}
			}
		}

		cnt++;
		for (int i = 0; i < m; i++) 
			cout << arr[i] << " ";
		cout << "\n";
	}

	return 0;
}