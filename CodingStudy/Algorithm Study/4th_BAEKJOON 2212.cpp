#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
set <int> s; //�������� ���� ��ġ�� �ִ°� �ǹ̰� �����Ƿ� �ϳ��� ģ��
//�Ÿ� ������ ���ĵ� �ȴ� set��
/*
position: 1    3     6   7     9
distance:    2    3    1    2
*/
int main() {
	scanf("%d %d", &N, &K); 
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		s.insert(num);
	}

	//���� �� ���鰣�� �Ÿ��� ���Ѵ�.
	auto it = s.end();
	it--;
	int total_dis = *it - *s.begin(); 

	//�����鰣�� �Ÿ��� ���Ѵ�
	vector<int>dis;
	int pre = *s.begin(), pos;
	for (auto it = ++s.begin(); it != s.end(); it++) {
		pos = *it;
		dis.push_back(pos - pre);
		pre = pos;
	}

	//�����鰣�� �Ÿ��� ������������ �����Ѵ�
	sort(dis.begin(), dis.end(), greater<>());

	//�����鰣�� �Ÿ� �� ���� ū K - 1���� ���� ��
	//�� �Ÿ����� ���ش�
	for (int i = 0; i < K - 1; i++) {
		if (i == dis.size())
			break;
		total_dis -= dis[i];
	}
	
	//�� ���
	printf("%d", total_dis);
	return 0;
}