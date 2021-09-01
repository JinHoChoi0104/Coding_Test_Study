#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N, S, M, num;
	scanf("%d %d %d", &N, &S, &M);
	map<int,int>m;
	m[S]++;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		map<int,int>tmp; //i��° �ܰ迡�� ���� �� �ִ� ������ ����� ��
		for (auto it = m.begin(); it != m.end(); it++) {
			int volume = it->first;
			if (volume + num <= M) //���� �ȿ� ���� ī��Ʈ ���ش�
				tmp[volume + num] += it->second;
			if (volume - num >= 0)
				tmp[volume - num] += it->second;
		}
		m.swap(tmp);
	}
	if (m.empty()) //���� �� �� ���� ���
		printf("-1");
	else { //map�� value�� ���� ���� �ǹǷ� ���� �ڿ� �� ��ȯ���ش�
		auto it = m.end();
		it--;
		printf("%d", it->first);
	}
	return 0;
}