#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int arr[5], num = 1;
	for (int i = 0; i < 5; i++) 
		cin >> arr[i];
	while (1) {
		int tmp = 0;
		for (int i = 0; i < 5; i++) 
			if (num % arr[i] == 0)
				tmp++;
		if (tmp >= 3)
			break;
		num++;
	}
	cout << num;
	return 0;
}	