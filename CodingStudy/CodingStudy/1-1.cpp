#include<iostream>
#include<queue>
using namespace std;

queue<int>q;
int main(void) {
	int N, num;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) 
		q.push(i);
	
	while (q.size()!=1) {
		q.pop();
		num = q.front();
		q.pop();
		q.push(num);
	}

	printf("%d", q.front());
	return 0;
}