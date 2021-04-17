#include <iostream>

using namespace std;

int main() {
	int a, b;
	while (1) {
		cin >> a >> b;
		if (cin.eof() == true) //eof get ^Z (ctrl + z)
			break;
		cout << a + b << "\n";
	}
	return 0;
}