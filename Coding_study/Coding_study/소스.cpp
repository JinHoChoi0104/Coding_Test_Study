#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int num, ans = 0;
	vector<int> arr;
	for (int i = 0; i < 4; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < 4; i++) {
		ans += arr[i];
	}
	int tmp1, tmp2;
	cin >> tmp1 >> tmp2;
	if (tmp1 > tmp2)
		ans += tmp1;
	else
		ans += tmp2;
	cout << ans;
	return 0;
} 