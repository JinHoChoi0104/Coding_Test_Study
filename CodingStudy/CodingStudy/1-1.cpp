#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, num, mid, l_size = 0, r_size = 0;
	scanf("%d", &N);
	priority_queue<int>l;
	priority_queue<int, vector<int>, greater<int>> r;
	// 1 2 (3)   (4) 5 6
	scanf("%d", &mid);
	N--;
	printf("%d\n", mid);

	while (N--) {
		scanf("%d", &num);
		if (l_size == r_size) {

			if (num >= mid) 
				r.push(num);
			else {
				l.push(num);
				r.push(mid);
				mid = l.top();
				l.pop();
			}
			r_size++;
		}
		else {
			if (num <= mid) 
				l.push(num);
			else {
				r.push(num);
				l.push(mid);
				mid = r.top();
				r.pop();
			}
			l_size++;
		}

		printf("%d\n", mid);
	}
}