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
	int p, m, l, num = 0; //num�� ���� �ִ� ���� ��
	string n;
	cin >> p >> m;
	bool isEmpty;
	vector<pair<int, string>> room[300]; //���ͷ� 2�� �迭 ����
	//1���� �� �ѹ�, 2���� �� �濡 �ִ� ������� ������ ����
	//room[i][j]
	vector<pair<int, int>> info(300); //�� ���� ������ ���� <����, ���� ����>
	//info[i]
	for (int i = 0; i < p; i++) {
		cin >> l >> n;
		isEmpty = false;
		for (int j = 0; j < num; j++) { //���� �ִ� ����� Ž��
			if (info[j].second < m && abs(info[j].first - l) <= 10) { //j��° �濡 ���� ������ �ְ�, �� ���� �������� ���̰� 10�����̴�
				room[j].push_back(make_pair(l, n));
				info[j].second++;
				isEmpty = true; //�� ���� �־ ���ٴ� ���� ǥ���ص�
				break; //�� �� �ִ� ���� ������ �� Ž�� �����
			}
		}
		if (!isEmpty) { //no room, make new room!
			room[num].push_back(make_pair(l, n));
			info[num++] = make_pair(l, 1);
		}
	}

	for (int i = 0; i < num; i++) //sorting
		sort(room[i].begin(), room[i].end(), compare); //pair���� �ι�° ��� ���ؼ� ����
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