#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	int n, from, to;
	vector<pair<int, int>> a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &from, &to);
		a.push_back(make_pair(from, to));
	}
	
	sort(a.begin(), a.end(), compare);
	
	vector<int>pos(n), tmp;
	tmp.push_back(a[0].second);
	pos[0] = 0;

	int index, k = n;
	for (int i = 1; i < n; i++) {
		if (tmp.back() < a[i].second) {
			pos[i] = tmp.size();
			tmp.push_back(a[i].second);
		}
		else {
			index = lower_bound(tmp.begin(), tmp.end(), a[i].second) - tmp.begin();
			tmp[index] = a[i].second;
			pos[i] = index;
		}
	}
	
	index = tmp.size()-1;
	vector<int> rest;
	
	
	for (int i = index; i >= 0; i--) {
		while (1) {
			k--;
			if (pos[k] == i) 
				break;
			else
				rest.push_back(a[k].first);
		}
	}

	while (k-- > 0) 
		rest.push_back(a[k].first);
	
	printf("%d\n", n - index-1);
	for (int i = rest.size() - 1; i >= 0 ; i--)
		printf("%d ", rest[i]);
	return 0;
}