#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
//누적합
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, Q, num, to, from;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < N; i++) //누적합으로 전환
		arr[i] += arr[i - 1];
	
	while (Q-- > 0) {
		cin >> to >> from;
		if (to == 1) //처음부터 구하는 경우
			cout << arr[from - 1] << "\n";
		else //중간부터 구하는 경우
			cout << arr[from - 1] - arr[to - 2] << "\n";
	}

	return 0;
}