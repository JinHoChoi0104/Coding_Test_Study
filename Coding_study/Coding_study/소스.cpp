#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int t, index;
	string str;
	for (cin >> t; t-- > 0;) {
		cin >> index >> str;
		for (int i = 0; i < str.size(); i++) {
			if (i == index-1)
				continue;
			cout << str[i];
		}
		cout << "\n";
	}
	return 0;
} 