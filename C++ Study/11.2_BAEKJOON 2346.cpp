#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, num;
	deque<pair<int,int>> q; 
	//���� �̿��ؼ� �������� Ǫ�� ���� �����ϵ����Ѵ�.
	cin >> n;
	for (int i = 1; i <= n; i++) { //�Է� �ޱ�
		cin >> num;
		q.push_back({ i, num });
	}
	int to_move = q.front().second;
	cout << q.front().first << " ";
	q.pop_front();
	while (!q.empty()) {
		if (to_move > 0) {//+�� ��� �տ��� �ڷ� ������
			for (int i = 1; i < to_move; i++) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else { //-�� ��� �ڿ��� ������ �����ش�
			to_move *= -1;
			for (int i = 0; i < to_move; i++) { //�տ��� �����ϴ� ���̹Ƿ� + ���� �ϳ� �� �ű��
				q.push_front(q.back());
				q.pop_back();
			} 
		}
		to_move = q.front().second; 
		cout << q.front().first << " ";
		q.pop_front();
	}

	return 0;
}