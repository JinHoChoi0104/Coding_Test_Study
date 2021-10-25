#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int x, y, date=0;
	cin >> x >> y;
	
	for (int i = 1; i < x; i++) {
		if (i == 2)
			date += 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			date += 30;
		else
			date += 31;
	}
	date += y;
	date %= 7;
	string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	cout << day[date];

	return 0;
}