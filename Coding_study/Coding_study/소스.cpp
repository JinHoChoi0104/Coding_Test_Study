#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, K, num;
	char c;
	cin >> N >> K;
	vector<int> arr;
	for (int i = 1; i < N; i++) {
		cin >> num >> c;
		arr.push_back(num);
	}
	cin >> num;
	arr.push_back(num);
	for (int i = 1; i <= K; i++) {
		vector<int>tmp;
		for (int j = 0; j < N - i; j++) 
			tmp.push_back(arr[j + 1] - arr[j]);
		arr.swap(tmp);
	}
	auto it = arr.begin();
	cout << *it;
	it++;
	for (; it != arr.end(); it++)
		cout << "," << *it;
	return 0;
}