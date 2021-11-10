#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, num;
	deque<pair<int,int>> q; 
	//덱을 이용해서 양쪽으로 푸시 팝이 가능하도록한다.
	cin >> n;
	for (int i = 1; i <= n; i++) { //입력 받기
		cin >> num;
		q.push_back({ i, num });
	}
	int to_move = q.front().second;
	cout << q.front().first << " ";
	q.pop_front();
	while (!q.empty()) {
		if (to_move > 0) {//+일 경우 앞에서 뒤로 보낸다
			for (int i = 1; i < to_move; i++) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else { //-일 경우 뒤에서 앞으로 보내준다
			to_move *= -1;
			for (int i = 0; i < to_move; i++) { //앞에서 추출하는 것이므로 + 보다 하나 더 옮긴다
				q.push_front(q.back());
				q.pop_back();
			} 
		}
		to_move = q.front().second; 
		cout << q.front().first << " ";
		q.pop_front();
	}

	return 0;
}