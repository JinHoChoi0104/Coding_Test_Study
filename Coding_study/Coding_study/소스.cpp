#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<int> arr;
	int num;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	char c;
	for (int i = 0; i < 3; i++) {
		cin >> c;
		if (c == 'A')
			cout << arr[0] << " ";
		else if ( c=='B')
			cout << arr[1] << " ";
		else
			cout << arr[2] << " ";
	}
	return 0;
}