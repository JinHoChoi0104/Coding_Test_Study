#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, string>& a, pair<int, string>& b) {
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int p, m, l, num = 0; //num은 현재 있는 방의 수
	string n;
	cin >> p >> m;
	bool isEmpty;
	vector<pair<int, string>> room[300]; //벡터로 2차 배열 구현
	//1차는 방 넘버, 2차는 그 방에 있는 사람들의 정보를 저장
	//room[i][j]
	vector<pair<int, int>> info(300); //각 방의 정보를 저장 <레벨, 남은 공간>
	//info[i]
	for (int i = 0; i < p; i++) {
		cin >> l >> n;
		isEmpty = false;
		for (int j = 0; j < num; j++) { //현재 있는 방들을 탐색
			if (info[j].second < m && abs(info[j].first - l) <= 10) { //j번째 방에 남은 공간이 있고, 그 방의 레벨제한 차이가 10이하이다
				room[j].push_back(make_pair(l, n));
				info[j].second++;
				isEmpty = true; //들어갈 방이 있어서 들어갔다는 것을 표시해둠
				break; //들어갈 수 있는 방이 있으면 방 탐색 멈춘다
			}
		}
		if (!isEmpty) { //no room, make new room!
			room[num].push_back(make_pair(l, n));
			info[num++] = make_pair(l, 1);
		}
	}

	for (int i = 0; i < num; i++) //sorting
		sort(room[i].begin(), room[i].end(), compare); //pair에서 두번째 요소 비교해서 정렬
	for (int i = 0; i < num; i++) {
		if (room[i].size() == m)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";
		for (int j = 0; j < room[i].size(); j++)
			cout << room[i][j].first << " " << room[i][j].second << "\n";
	}
	return 0;
}