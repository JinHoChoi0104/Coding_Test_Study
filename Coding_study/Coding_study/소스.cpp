#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int ans = 0;
	char s;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> s;
			if(s=='F')
				if ((i + j) % 2 == 0)
					ans++;
		}
	}
	cout << ans;

	return 0;
}