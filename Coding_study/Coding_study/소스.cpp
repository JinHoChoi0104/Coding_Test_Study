#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str, arr[3] = { "ABCABCABCABC", "BABCBABCBABC", "CCAABBCCAABB" }, name[3] = {"Adrian", "Bruno", "Goran"};
	int n, num[3] = {0,0,0};
	int max_num = 0;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		int index = i % 12;
		for (int j = 0; j < 3; j++) 
			if (arr[j][index] == str[i])
				num[j]++;
	}
	for (int i = 0; i < 3; i++) 
		max_num = max(max_num, num[i]);
	cout << max_num << "\n";
	for (int i = 0; i < 3; i++)
		if (max_num == num[i])
			cout << name[i] << "\n";
	return 0;
}