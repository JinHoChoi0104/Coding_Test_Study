#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	string str;
	cin >> t;
	for (int i = 1; i <= t ; i++) {
		cin >> str;
		cout << "String #" << i << "\n";
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'Z')
				str[j] = 'A';
			else
				str[j]++;
		}
		cout << str << "\n\n";
	}
	return 0;
}