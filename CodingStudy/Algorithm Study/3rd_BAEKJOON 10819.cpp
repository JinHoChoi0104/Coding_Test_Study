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
		dq.push_front(arr.front()); //���� ���� ���� ���� �ְ�
		dq.push_back(arr.back()); //���� ū ���� �ڿ�
		arr.pop_front(), arr.pop_back();
		if (N == 3) break;
		dq.push_front(arr.back()); //�� �������� ū ���� �տ�
		arr.pop_back();
		if( N == 4) break;
		dq.push_back(arr.front()); //���� �� �� ���� ���� ���� �տ��� �־��� ���� ū �� ������
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
	else  //���� �ϳ��� ���� �� �� �� ���̰� ū ������
		dq.push_back(arr.front());

	int ans = 0;
	for (int i = 0; i < N - 1; i++) 
		ans += abs(dq[i] - dq[i + 1]);
	
	cout << ans;
		
	return 0;
}