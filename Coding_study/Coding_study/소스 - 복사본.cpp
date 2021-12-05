#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int ans = 0;

void getEnergy(list<int>li, int *it, int power) {
	auto tmp1 = it, tmp2 = it;
	tmp1--, tmp2++;
	power += *tmp1 * *tmp2;
	li.remove(*it);
	if (li.size() == 2) {
		ans = max(ans, power);
		return;
	}
	for (auto it = li.begin(); it != li.end(); it++)
		cout << *it;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num;
	list<int>li;
	for (cin >> n; n-- > 0;) {
		cin >> num;
		li.push_back(num);
	}
	int ans = 0;
	auto it = li.begin();
	for (it++; it != li.begin(); it++)
		getEnergy(li, it, 0);

	cout << ans;
	return 0;
}	