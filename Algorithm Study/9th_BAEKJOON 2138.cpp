#include <iostream>
#include <algorithm>
using namespace std;

int N;
string target;
void changeNUM(string& num, int index) {
	for (int i = index - 1; i <= index + 1; i++) {
		if (i == N || i == -1) //범위 벗어나면 패스
			continue;
		if (num[i] == '0')
			num[i] = '1';
		else
			num[i] = '0';
	}
}
int LED(string str) {
	int cnt1 = 1, cnt2 = 0, ans = -1;
	string tmp1 = str, tmp2 = str;
	// 첫번째 스위치를 클릭한 경우
	changeNUM(tmp1, 0);
	for (int i = 1; i < N; i++) {
		if (target[i - 1] != tmp1[i - 1]) {
			changeNUM(tmp1, i);
			cnt1++;
		}
	}
	if (tmp1 == target) //목표 상태인지 체크
		ans = cnt1;
	// 스위치를 클릭하지 않은 경우
	for (int i = 1; i < N; i++) {
		if (target[i - 1] != tmp2[i - 1]) {
			changeNUM(tmp2, i);
			cnt2++;
		}
	}
	if (tmp2 == target)
		ans = max(ans, cnt2);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	string str;
	cin >> str >> target;
	if (str == target) { //이미 일치하는 경우
		cout << 0;
		return 0;
	}

	cout << LED(str);
	return 0;
}