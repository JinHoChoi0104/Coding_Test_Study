#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	//freopen("input.txt", "r", stdin);
	int n, m, num;
	ll sum = 0;
	//priority_queue <int> p_q; //descending order (p_q.top() returns biggest num)
	priority_queue <ll, vector<ll>,greater<ll>> p_q; //ascending order (p_q.top() returns smallest num)
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%d", &num);
		p_q.push(num);
	}
	ll a, b;
	while (m-- > 0) { // pop two numbers from priority queue
		a = p_q.top(), p_q.pop(); // smallest num
		b = p_q.top(), p_q.pop(); // 2nd smallest num
		a += b, b = a; // add both
		p_q.push(a), p_q.push(b); // push
	}
	while (!p_q.empty()) {
		sum += p_q.top();
		p_q.pop();
	}
	printf("%lld", sum);
	return 0;
}