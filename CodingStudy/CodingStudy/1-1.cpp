#include <iostream>

using namespace std;

int main() {
	string str = "0123456789abc";
	cout << str << "\n*divide string into substrings, 4 charcter per line*\n";
	for(int i=0; i<str.length();i += 4)
		cout << str.substr(i,4) << "\n";

	string str2 = "01234567";
	cout << "\n" << str2 << "\n*extract substring starting from index: 5*\n";
	cout << str2.substr(5) << endl;
	return 0;
}