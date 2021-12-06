#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
void getEnergy(vector<int>arr, int index, int power) {
	power += arr[index - 1] * arr[index + 1];
	arr.erase(arr.begin()+index);
	if (arr.size() == 2) {
		ans = max(ans, power);
		return;
	}
	for (int i = 1; i < arr.size() - 1; i++)
		getEnergy(arr, i, power);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num;
	vector<int>arr;
	for (cin >> n; n-- > 0;) {
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 1; i < arr.size() - 1; i++)
		getEnergy(arr, i, 0);
	cout << ans;
	return 0;
}