#include <iostream>
#include <queue>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<ll, vector<ll>, greater<>>pq; 
	//������������ ���� �ǵ��� �ؼ� ���� ������ pop�ȴ�
	int N, num;
	ll jun;
	cin >> N >> jun;
	for (int i = 1; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty()) {
		if (jun > pq.top()) { //�ؿ��̰� �̱� �� �ִ�
			jun += pq.top();
			pq.pop();
		}
		else //�̱� �� ����
			break; //������ �ο��鵵 �� �̱�Ƿ� break
	}
	if (pq.empty()) //��� �̰��
		cout << "Yes";
	else //�̱��� ���� ����� �ִ�
		cout << "No";
	return 0;
}