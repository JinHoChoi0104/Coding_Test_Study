#include <iostream>
using namespace std;
bool arr[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	cin >> str;
	arr[0] = true;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C') {
			if (!arr[0] && !arr[2])
				continue;
			if (arr[0])
				arr[0] = false, arr[2] = true;
			else
				arr[2] = false, arr[0] = true;
		}
		else if (str[i] == 'B') {
			if (!arr[1] && !arr[2])
				continue;
			if (arr[1])
				arr[1] = false, arr[2] = true;
			else
				arr[2] = false, arr[1] = true;
		}
		else {
			if (!arr[0] && !arr[1])
				continue;
			if (arr[1])
				arr[1] = false, arr[0] = true;
			else
				arr[0] = false, arr[1] = true;
		}
	}
	for (int i = 0; i < 3; i++)
		if (arr[i])
			cout << i + 1;
	return 0;
}