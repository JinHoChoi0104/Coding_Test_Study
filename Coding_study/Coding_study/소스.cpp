#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	char c, tmp;
	while (1) {
		cin >> c;
		if (c == '#')
			break;
		tmp = c - 32;
		getline(cin, str, '\n');
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) 
			if (str[i] == c || str[i] == tmp)
				cnt++;
		cout << c << " " << cnt << "\n";
	}
	
	return 0;
}