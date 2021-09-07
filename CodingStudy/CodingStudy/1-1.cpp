#include <iostream>
#include <queue>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<ll, vector<ll>, greater<>>pq; 
	//오름차순으로 정렬 되도록 해서 작은 수부터 pop된다
	int N, num;
	ll jun;
	cin >> N >> jun;
	for (int i = 1; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty()) {
		if (jun > pq.top()) { //준원이가 이길 수 있다
			jun += pq.top();
			pq.pop();
		}
		else //이길 수 없다
			break; //나머지 인원들도 못 이기므로 break
	}
	if (pq.empty()) //모두 이겼다
		cout << "Yes";
	else //이기지 못한 사람도 있다
		cout << "No";
	return 0;
}