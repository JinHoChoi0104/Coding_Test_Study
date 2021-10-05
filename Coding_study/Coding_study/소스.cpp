#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	string str, ans = "";
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		if (i % N == 0)
			ans = ans + str[i];

	cout << ans;
	return 0;
}