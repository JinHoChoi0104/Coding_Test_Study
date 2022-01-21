#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num;
	char s[100];
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cin.getline(s, 100, '\n');
		if(s[0]>='a' && s[0] <='z')	
			s[0] -= 32;
		cout << s <<"\n";
	}	
	return 0;
}