#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<int>arr(4);
	for (int i = 0; i < 4; i++) 
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	cout << arr[0] * arr[2];
	return 0;
}