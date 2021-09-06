#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

struct box { int from, to, num; };

bool compare(const box& a, const box& b) {
	if (a.to == b.to)
		return a.from > b.from;
	return a.to < b.to;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<box>v;
	vector<int> truck(2001, 0); //i��° ������ �������� ������ �ִ� �ڽ��� ��
	int N, C, M, from, to, num, volume, ans = 0, tmp = 0, index = 0;


	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> num;
		v.push_back({ from, to, num });
	}

	sort(v.begin(), v.end(), compare);
	/* �������� ����� �� �켱 ���� 
	�������� ���� ���� ���������� ����� ���� ������ ���� �����Ѵ�
	�������� ���� ���� ��� ���ɼ��� ũ�� �����̴�
	*/
	for (int i = 2; i <= N; i++) { //��ǥ ������
		while (i > v[index].to) { //�Է� ���� �����鿡�� ��ǥ �������� �̵��Ѵ�
			index++;
			if (index == M) //�迭 ��������
				break;
		}
		if (index == M)
			break;
		while (i == v[index].to) {
			volume = 0;
			/*
			1�� �������� 4�� ������ �� ��
			4�� ���������� ��¥�� ���� �����ϱ�
			truck���� 1������ 3�� ���� ���� ���� �ư� ���� ������ �������ָ� �ȴ�.
			*/
			for (int j = v[index].from; j < i; j++)
				volume = max(volume, truck[j]);
			/*
			volume = �ڽ��� �Ǿ �������� �Ǵ� ������ �߿��� 
			���� �ڽ��� ���� �ư� ������ ��
			C - volume = Ʈ���� �ư� �� �� �ִ� �ִ� �ڽ� ��
			*/
			if (C - volume > v[index].num) { //���� �� �ִ� �ڽ� ���� ������ �ڽ����� �� ���� ��
				for (int j = v[index].from; j < i; j++)
					truck[j] += v[index].num;
				ans += v[index].num;
			}
			else { //���� �� �ִ� �ڽ����� ������ �ڽ��� �� ���� ��
				for (int j = v[index].from; j < i; j++)
					truck[j] += C - volume;
				ans += C - volume;
				break;
				/*
				�������� �������� �������ε� ������ �����̴�
				Ʈ���� �ڽ��� ���� ĭ�� ���ٴ� ���� ���������� �� �� ���� �翬��
				�Ǿ �� �� ���ٴ� ���̴�.
				*/
			}
			index++;
			if (index == M)
				break;
		}
		if (index == M)
			break;
	}

	cout << ans;

	return 0;
}