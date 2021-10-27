#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	char c;
	int min = 0;
	map <char, int> m;
	while (cin >> c) {
		m[c]++;
		if (m[c] > min)
			min=m[c];
	}
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second == min)
			cout << it->first;

	return 0;
}