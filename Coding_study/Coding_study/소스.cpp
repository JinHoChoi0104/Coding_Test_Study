#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string num;
	long long mul1 = 0, mul2 = 0;
	cin >> num;
	for(int i=0; i<num.size(); i++)
		mul1 += int(num[i] - '0');
	cin >> num;
	for (int i = 0; i < num.size(); i++)
		mul2 += int(num[i] - '0');
	cout << mul1 * mul2;
	return 0;
}