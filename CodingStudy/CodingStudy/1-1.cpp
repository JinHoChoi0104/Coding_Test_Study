#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "get string by only cin: " ;
	cin >> str;
	cout << str << endl;

	cout << "get string by getline: " ;
	getline(cin, str);
	cout << str << endl;
	
	return 0;
}