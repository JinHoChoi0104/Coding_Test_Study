#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int max_snow = 0, N, M;
struct snow { int size, cnt, pos; };
queue<snow> q;
vector<int> a;
void rolling() { //Brute Force!
	int size, cnt, pos;
	while (!q.empty()) { // you can use recursion instead of using queue
		size = q.front().size, cnt = q.front().cnt, pos = q.front().pos;
		q.pop();
		if (cnt == M || pos == N)
			max_snow = max(max_snow, size);
		else {
			if (pos < N) // case 1
				q.push({ size + a[pos + 1], cnt + 1, pos + 1 });

			if (pos < N - 1) // case 2
				q.push({ size / 2 + a[pos + 2], cnt + 1, pos + 2 });
		}
	}
}
/*
Why not Greed !???
since you have chance to arrive at ending point before time M
you have to check every cases!!
=> Brute Force!!
*/
int main(void) {
	scanf("%d %d", &N, &M);

	int num;
	a.push_back(0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		a.push_back(num);
	}
	q.push({ 1, 0, 0 });
	rolling();
	printf("%d", max_snow);
	return 0;
}