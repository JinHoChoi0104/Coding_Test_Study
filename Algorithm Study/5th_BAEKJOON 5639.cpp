#include <iostream>
#include <vector>
using namespace std;

vector<int>arr;

void findroot(int l, int r) { //��Ʈ�� ã�´�
	if (r < l)
		return;
	int i;
	for (i = l + 1; i <= r; i++) //��Ʈ���� ū ���� ã�� �� ���� �������� ���� ���� �ڽ� ���Ž��
		if (arr[i] > arr[l]) break;

	findroot(l + 1, i - 1); //���� �ڽ� ��� Ž��
	findroot(i, r); //������ �ڽ� ��� Ž��
	printf("%d\n", arr[l]); //�������� ��� ���
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	while (cin >> num) //ctrl + z ���ö����� �Է� �޴´�
		arr.push_back(num);

	findroot(0, arr.size()-1);

	return 0;
}