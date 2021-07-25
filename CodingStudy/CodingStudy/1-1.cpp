#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);
	queue<int>q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	printf("<", q.front());
	while (q.size()!=1) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>", q.front());

	return 0;
}