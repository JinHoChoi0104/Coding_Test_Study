#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, num;
	cin >> N;
	deque<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	deque<int> dq;
	while (1) {
		dq.push_front(arr.front()); //제일 작은 수를 먼저 넣고
		dq.push_back(arr.back()); //제일 큰 수를 뒤에
		arr.pop_front(), arr.pop_back();
		if (N == 3) break;
		dq.push_front(arr.back()); //그 다음으로 큰 수를 앞에
		arr.pop_back();
		if( N == 4) break;
		dq.push_back(arr.front()); //남은 수 중 제일 작은 수를 앞에서 넣었던 제일 큰 수 옆으로
		arr.pop_front();
		if (N == 5) break;
		dq.push_front(arr.front());
		arr.pop_front();
		if (N == 6) break;
		dq.push_back(arr.back());
		arr.pop_back();
		if (N == 7) break;
		dq.push_front(arr.back());
		arr.pop_back();
		break;
	}
	if (abs(dq.front() - arr.front()) > abs(dq.back() - arr.front()))
		dq.push_front(arr.front());
	else  //남은 하나의 수는 앞 뒤 중 차이가 큰 곳으로
		dq.push_back(arr.front());

	int ans = 0;
	for (int i = 0; i < N - 1; i++) 
		ans += abs(dq[i] - dq[i + 1]);
	
	cout << ans;
		
	return 0;
}