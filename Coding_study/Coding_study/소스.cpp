#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num = 1;
	while (1) {
		vector<bool>tmp(101,false);
		int cnt = 0;
		while (1) {
			cin >> num;
			if (num < 1)
				break;	
			tmp[num] = true;
		}
		if (num == -1)
			break;
		for (int i = 1; i <= 50; i++)
			if (tmp[i] && tmp[i * 2])
				cnt++;
		cout << cnt << "\n";
	}
	
	return 0;
}