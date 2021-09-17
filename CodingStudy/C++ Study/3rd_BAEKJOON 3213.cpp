#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int t, pi[3] = {0,0,0};
	string str;
	for (cin >> t; t-- > 0;) {
		cin >> str;
		if (str == "1/4")
			pi[0]++;
		else if (str == "1/2")
			pi[1]++;
		else
			pi[2]++;

	}
	int cnt = pi[1] / 2; //반 조각 먼저 카운트 
	pi[1] %= 2;  //반조각 없거나 하나 남는다

	if (pi[2] >= pi[0]) { // 3/4 조각이 더 많을 때
		cnt += pi[2]; // 3/4 조각만큼 시키고 1/4조각은 그곳에 끼워 넣으면 된다 
		cnt += pi[1];
	}
	else { // 1/4조각이 더 많거나 같을 때
		cnt += pi[2];
		pi[0] -= pi[2]; //남은 1/4조각
		if (pi[1] == 0) { //남은 1/2조각이 없다
			cnt += pi[0] / 4;
			if (pi[0] % 4 != 0)
				cnt++;
		}
		else {
			cnt++; // 우선 1/2조각 카운트 
			if (pi[0] > 2) { // 1/4조각이 2개 초과 했으면 그것도 카운트
				pi[0] -= 2;
				cnt += pi[0] / 4;
				if (pi[0] % 4 != 0)
					cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}