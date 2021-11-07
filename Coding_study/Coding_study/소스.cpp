#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, M, num;
	set<int> arr;
	for (cin >> N; N-- > 0;) {
		cin >> num;
		arr.insert(num);
	}
	for (cin >> M; M-- > 0; ) {
		cin >> num;
		if (arr.find(num) != arr.end())
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}