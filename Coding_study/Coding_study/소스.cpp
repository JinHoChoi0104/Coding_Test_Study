#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

bool compare(const student& a, const student& b) { //정렬 방법 따로 선언
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math)
				return a.name < b.name;
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<student>v;
	int N, a, b, c;
	string str;
	for (cin >> N; N-- > 0; ) {
		cin >> str >> a >> b >> c;
		v.push_back({ str,a,b,c });
	}
	sort(v.begin(), v.end(), compare); //정렬
	for (auto it = v.begin(); it != v.end(); it++)
		cout << it->name << "\n"; //결과 출력
	return 0;
}