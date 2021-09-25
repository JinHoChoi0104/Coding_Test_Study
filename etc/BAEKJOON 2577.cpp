#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string result(to_string(a*b*c)); //int to string

	char* arr = new char[result.length() + 1]; // string to int array
	memmove(arr, result.c_str(), result.length());

	int* mul = new int[result.length() + 1];
	for (int i = 0; i < result.length(); i++)
		mul[i] = arr[i] - '0'; // char to int

	int num[10];
	for (int i = 0; i < 10 ; i++)
		num[i] = 0;

	for (int i = 0; i < result.length(); i++) {
		switch (mul[i]) {
		case 0:
			num[0]++;
			break;
		case 1:
			num[1]++;
			break;
		case 2:
			num[2]++;
			break;
		case 3:
			num[3]++;
			break;
		case 4:
			num[4]++;
			break;
		case 5:
			num[5]++;
			break;
		case 6:
			num[6]++;
			break;
		case 7:
			num[7]++;
			break;
		case 8:
			num[8]++;
			break;
		case 9:
			num[9]++;
			break;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << num[i] << "\n";
	
	return 0;
}