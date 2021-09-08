#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K, cnt = 0, ans = 0; // cnt�� �������� 0�� ĭ ���� ����
	cin >> N >> K;

	deque<int> dq1(N), dq2(N);
	deque <int> robot; // �κ��� ��ġ ����

	for (int i = 0; i < N; i++)
		cin >> dq1[i];
	for (int i = N - 1; i >= 0; i--)
		cin >> dq2[i];

	while (cnt < K) { // 4.�ݺ�
		// 1.��Ʈ �̵�
		dq2.push_back(dq1.back());
		dq1.pop_back();
		dq1.push_front(dq2.front());
		dq2.pop_front();
		// �κ��� �̵�
		for (auto it = robot.begin(); it != robot.end(); it++)
			(*it)++;
		// ������ ��ġ�� ������ �κ� �����ش�
		if (!robot.empty())
			if (robot.back() == N - 1)
				robot.pop_back();
		
		if (!robot.empty()) {// �κ��� ������
			bool isDrop = false;
			int tmp = robot.size() - 1;
			for (int i = tmp; i >= 0; i--) { // 2.���� �ö� �κ�����
				if (i == tmp) { // ���� ���� �ö� �κ��� �������� ������
					if (dq1[robot.back() + 1] > 0) {
						robot.back()++;
						dq1[robot.back()]--;
						if (robot.back() == N - 1)
							isDrop = true; // ������ ��ġ��! �����°� ����
						if (dq1[robot.back()] == 0)
							cnt++;
					}
				}
				else { // ������ �κ�
					if (dq1[robot[i] + 1] > 0 && robot[i + 1] != robot[i] + 1) {
						robot[i]++;
						dq1[robot[i]]--;
						if (dq1[robot[i]] == 0)
							cnt++;
					}
				}
			}
			if (isDrop)
				robot.pop_back();
		}

		if (dq1[0] > 0) { // 3.�ø��� ��ġ�� �������� 0 �̻��̸�
			dq1[0]--;
			robot.push_front(0); //�κ� �ø���
			if (dq1[0] == 0)
				cnt++;
		}
		ans++; //�ܰ� ī��Ʈ
	}

	cout << ans;
	return 0;
}