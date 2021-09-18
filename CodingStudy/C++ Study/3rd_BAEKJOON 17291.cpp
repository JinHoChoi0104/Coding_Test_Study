#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N;
	cin >> N;
	//���� ���� ���� ����
	vector<int> odd = {0, 1, 0, 0, 0}; //Ȧ�� �⵵�� �¾ ������ 
	vector<int> even(5,0); //¦�� �⵵�� �¾
	for (int i = 2; i <= N; i++) { //2�� ° ���� ����
		int sum = even[4];
		even[4] = even[3]; //¦���⵵�� ź���� ��ü�� 1�� �� ���
		for (int k = 3; k > 0; k--) { 
			sum += (odd[k] + even[k]); //�� �����ϴ� ��ä ���Ѵ�
			odd[k] = odd[k - 1], even[k] = even[k - 1];  //�� �쾿 ���̵��, ����ϴ� ��ü�� ���⼭ �����
		}
		

		if (i % 2 == 0)  //¦���⵵�� ź��
			even[1] = sum;
		else //�Ǽ��⵵�� ź��
			odd[1] = sum;
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		ans += (odd[i] + even[i]);
	cout << ans;
	return 0;
}