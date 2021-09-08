#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K, cnt = 0, ans = 0; // cnt에 내구도가 0인 칸 갯수 저장
	cin >> N >> K;

	deque<int> dq1(N), dq2(N);
	deque <int> robot; // 로봇의 위치 저장

	for (int i = 0; i < N; i++)
		cin >> dq1[i];
	for (int i = N - 1; i >= 0; i--)
		cin >> dq2[i];

	while (cnt < K) { // 4.반복
		// 1.벨트 이동
		dq2.push_back(dq1.back());
		dq1.pop_back();
		dq1.push_front(dq2.front());
		dq2.pop_front();
		// 로봇도 이동
		for (auto it = robot.begin(); it != robot.end(); it++)
			(*it)++;
		// 내리는 위치에 있으면 로봇 내려준다
		if (!robot.empty())
			if (robot.back() == N - 1)
				robot.pop_back();
		
		if (!robot.empty()) {// 로봇이 있으면
			bool isDrop = false;
			int tmp = robot.size() - 1;
			for (int i = tmp; i >= 0; i--) { // 2.먼저 올라간 로봇부터
				if (i == tmp) { // 가장 먼저 올라간 로봇은 내릴수도 있으니
					if (dq1[robot.back() + 1] > 0) {
						robot.back()++;
						dq1[robot.back()]--;
						if (robot.back() == N - 1)
							isDrop = true; // 내리는 위치다! 내리는거 예약
						if (dq1[robot.back()] == 0)
							cnt++;
					}
				}
				else { // 나머지 로봇
					if (dq1[robot[i] + 1] > 0 && robot[i + 1] != robot[i] + 1) {
						robot[i]++;
						dq1[robot[i]]--;
						if (dq1[robot[i]] == 0)
							cnt++;
					}
				}
			}
			if (isDrop)
				robot.pop_back();
		}

		if (dq1[0] > 0) { // 3.올리는 위치에 내구도가 0 이상이면
			dq1[0]--;
			robot.push_front(0); //로봇 올린다
			if (dq1[0] == 0)
				cnt++;
		}
		ans++; //단계 카운트
	}

	cout << ans;
	return 0;
}