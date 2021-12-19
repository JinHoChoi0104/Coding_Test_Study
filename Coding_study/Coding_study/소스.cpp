#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, num;
	cin >> n >> m;
	priority_queue<int> pq;
	priority_queue<int, vector<int>,greater<int>> concent;
	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < m; i++)
		concent.push(0);
	while (!pq.empty()) {
		int tmp = concent.top() + pq.top();
		concent.pop(), pq.pop();
		concent.push(tmp);
	}
	int ans;
	while (!concent.empty()) {
		ans = concent.top();
		concent.pop();
	}
	cout << ans;
	return 0;
}