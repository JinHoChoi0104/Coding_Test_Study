#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num;
	priority_queue<int>pq;
	for (cin >> n; n-- > 0;) {
		cin >> num;
		pq.push(num);
	}
	int index, a, b;
	cin >> index;
	while (pq.top() >= index) {
		if (pq.top() == index) {
			cout << 0;
			return 0;
		}
		b = pq.top();
		pq.pop();
		if (pq.empty()) {
			a = 0;
			break;
		}
		a = pq.top();
	}
	cout << (b - index) * (index - a) - 1;
	return 0;
}	