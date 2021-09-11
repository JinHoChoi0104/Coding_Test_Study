#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector <char> c[20];
map <string, int> ans;
vector<bool>isL(11, false);
vector<char> v;

void findMember(int index, string str) { //공통 메뉴로 코스 만들기
	if (index == v.size())
		return;
	string str2;
	for (int i = index; i < v.size(); i++) {
		str2 = str + v[i];
		if (isL[str2.size()])
			ans[str2]++;
		findMember(i + 1, str2);
	}
}

void CS(int a, int b) { //공통 메뉴 찾기
	int len1 = c[a].size(), len2 = c[b].size();
	v.clear();
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
			if (c[a][i] == c[b][j])
				v.push_back(c[a][i]);

	string str = "";
	for (int i = 0; i < v.size(); i++) {
		str = v[i];
		findMember(i + 1, str);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	int N = orders.size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < orders[i].size(); j++)
			c[i].push_back(orders[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < c[i].size(); j++)
			sort(c[i].begin(), c[i].end());

	for (int i = 0; i < course.size(); i++)
		isL[course[i]] = true;

	vector<string> answer;
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			CS(i, j);

	vector<int> max_len(11, 0);
	for (auto it = ans.begin(); it != ans.end(); it++) { //코스 길이별 가장 큰 캣수 구하기
		string tmp = it->first;
		max_len[(int)tmp.size()] = max(max_len[(int)tmp.size()], it->second);
	}
	for (auto it = ans.begin(); it != ans.end(); it++) { //위에서 구한 갯수와 같은 메뉴 추출
		string tmp = it->first;
		if (max_len[(int)tmp.size()] == it->second)
			answer.push_back(it->first);
	}

	sort(answer.begin(), answer.end());
	return answer;
}