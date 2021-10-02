#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
bool comp(const pii &a, const pii &b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, num, M, max_mass = 0;
	cin >> N;
	vector<pii> crane;
	for (int i = 0; i < N;i++) {
		cin >> num;
		crane.push_back({ num,0 });
		max_mass = max(num, max_mass);
	}
	sort(crane.begin(), crane.end());
	bool movable = true;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (num > max_mass) {
			movable = false;
			continue;
		}
		int index = lower_bound(crane.begin(), crane.end(), pii(num, 0), comp) - crane.begin();
		crane[index].second++;
	}
	if (!movable) { //모든 박스 옮길 수 없다
		cout << -1;
		return 0;
	}
	int total_moved = 0, cnt = 0;
	while (total_moved != M) {
		cnt++;
		int sum = 1; 
		for (int i = N - 1; i >= 0; i--) { //무거운거 옮길 수 있는 크레인부터 확인
			int& ret = crane[i].second; //이동 필요한 박스
			if (ret == 0) { //자기 할당 없으면 다음 것 도와준다
				sum++;
				continue;
			}
			if (sum >= ret) { //옮길 수 있는 박스가 더 많은 경우
				sum -= ret, total_moved += ret;
				ret = 0;
				sum++;
			}
			else if (sum < ret){ //더 적은 경우
				ret -= sum, total_moved += sum;
				sum = 1;
			}
		}
	}
	cout << cnt;
	return 0;
}