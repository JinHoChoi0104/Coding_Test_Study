#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	set<string> ans;
	vector<string> arr;
	int n, k;
	cin >> n >> k;
	string num;
	for (int i = 0; i < n; i++) { 
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end()); //조합 만들기 전 정렬
		
	do {
		string tmp="";
		for (int i = 0; i < k; i++)
			tmp = tmp + arr[i];
		ans.insert(tmp); //중복 제거용
	} while (next_permutation(arr.begin(), arr.end())); //조합 만들기

	cout << ans.size();
	return 0;
}