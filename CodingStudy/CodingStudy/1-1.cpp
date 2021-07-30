#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void NM(int index, int cnt, list<int>& pre, list <int>& remain) {
	list <int> l(pre);
	list <int> l2(remain);
	list <int> ::iterator iter = l2.begin();

	for (int i = 0; i < index; i++)
		iter++;

	l.push_back(*iter);
	l2.erase(iter);

	if (cnt == 0) {
		for (iter = l.begin(); iter != l.end(); iter++)
			printf("%d ", *iter);
		printf("\n");
		return;
	}
	for (int i = 0; i < l2.size(); i++)
		NM(i, cnt - 1, l, l2);
}

int main(void) {
	int N, M, num;
	scanf("%d %d", &N, &M);

	list <int> l, l2;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		l2.push_back(num);
	}

	l2.sort();

	for (int i = 0; i < N; i++)
		NM(i, M - 1, l, l2);

	return 0;
}