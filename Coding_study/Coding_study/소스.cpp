#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	map<int, int> A, B;
	int T, n, m, num;
	cin >> T >> n >> num;
	vector<int> arr;
	arr.push_back(num);
	for (int i = 1; i < n; i++) {
		cin >> num;
		arr.push_back(arr.back() + num);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == 0)
				A[arr[j]]++;
			else 
				A[arr[j] - arr[i - 1]]++;
		}
	}

	cin >> m >> num;
	arr.clear();
	arr.push_back(num);
	for (int i = 1; i < m; i++) {
		cin >> num;
		arr.push_back(arr.back() + num);
	}
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (i == 0)
				B[arr[j]]++;
			else
				B[arr[j] - arr[i - 1]]++;
		}
	}

	long long ans = 0;
	for (auto it = A.begin(); it != A.end(); it++) {
		int A_sum = it->first;
		ans += (long long) it->second * B[T - A_sum];
	}

	cout << ans;

	return 0;
}