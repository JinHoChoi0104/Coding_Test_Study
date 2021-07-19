#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	string arr;
	cin >> arr;

	cout << arr.substr(N - 5);
	return 0;
}