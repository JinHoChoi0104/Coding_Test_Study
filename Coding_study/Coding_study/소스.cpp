#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T;
	string str;
	
	for (cin >> T; T-- > 0;) {
		vector<int> arr(8, 0);
		cin >> str;
		for (int i = 0; i < 38; i++) {
			string tmp = str.substr(i, 3);
			if (tmp == "TTT")
				arr[0]++;
			else if (tmp == "TTH")
				arr[1]++;
			else if (tmp == "THT")
				arr[2]++;
			else if (tmp == "THH")
				arr[3]++;
			else if (tmp == "HTT")
				arr[4]++;
			else if (tmp == "HTH")
				arr[5]++;
			else if (tmp == "HHT")
				arr[6]++;
			else
				arr[7]++;
		}
		for (int i = 0; i < 8; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	return 0;
}