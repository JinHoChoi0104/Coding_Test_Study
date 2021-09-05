#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

struct box { int from, to, num; };

bool compare(const box& a, const box& b) {
	if (a.to == b.to)
		return a.from > b.from;
	return a.to < b.to;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<box>v;
	vector<int> truck(2001, 0);
	int N, C, M, from, to, num, volume, ans = 0, tmp =0, index = 0;
	

	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> num;
		v.push_back({ from, to, num });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 2; i <= N; i++) {
		while (i > v[index].to) {
			index++;
			if (index == M)
				break;
		}
		if (index == M)
			break;
		while (i == v[index].to) {
			volume = 0;
			for (int j = v[index].from; j < i; j++) 
				volume = max(volume, truck[j]);

			if (C - volume > v[index].num) {
				for (int j = v[index].from; j < i; j++) 
					truck[j] += v[index].num;
				ans += v[index].num;
			}
			else {
				for (int j = v[index].from; j < i; j++) 
					truck[j] += C - volume;
				ans += C - volume;
				break;
			}
			index++;
			if (index == M)
				break;
		}
		if (index == M)
			break;

	}

	cout << ans;

	return 0;
}