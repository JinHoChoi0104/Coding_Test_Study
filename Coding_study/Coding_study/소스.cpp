#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	set<int> day, arr;
	int N, C, num;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (day.find(num) != day.end())
			continue;
		if (num > C)
			continue;
		for (int j = num; j <= C; j += num)
			day.insert(j);
	}
	cout << day.size();
	return 0;
}