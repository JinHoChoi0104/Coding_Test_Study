#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	map<char, double> grade;
	grade['A'] = 4.0, grade['B'] = 3.0, grade['C'] = 2.0, grade['D'] = 1.0;

	char c1, c2;
	cin >> c1;
	if (c1 == 'F') {
		cout << fixed;
		cout.precision(1);
		cout << 0.0;
		return 0;
	}
	cin >> c2;
	double ans = grade[c1];
	if (c2 == '+')
		ans += 0.3;
	else if(c2=='-')
		ans -= 0.3;

	cout << fixed;
	cout.precision(1);
	cout << ans;
	return 0;
}