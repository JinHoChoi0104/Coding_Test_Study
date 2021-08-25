#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int>arr(100);
map<int, long long>m; //index���� ����ؼ� ���� ��, �� ���� ����
int N;
long long cnt = 0;
void DFS(int index) { //����ؾߵ� ���� �ε���
	if(index == N-1) { //��� ����� ������ ��
		for (auto it = m.begin(); it != m.end(); it++)
			if (it->first == arr[N - 1])
				cnt+=it->second; //ī��Ʈ �Ѵ�
		return;
	}
	int a, b;
	map<int, long long>tmp; //�ӽ� �����
	for (auto it = m.begin(); it != m.end(); it++) {
		a = it -> first + arr[index], b = it -> first - arr[index];
		if (a >= 0 && a <= 20)
			tmp[a] += it -> second;
		if (b >= 0 && b <= 20)
			tmp[b] += it -> second;
	}
	m.swap(tmp); //�������ش�
	DFS(index + 1);
}

int main(void) {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);

	m[arr[0]]++;
	DFS(1);

	printf("%lld", cnt);
	return 0;
}