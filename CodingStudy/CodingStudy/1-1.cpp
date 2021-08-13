#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	int len = str.length(), ret = 0;
	vector<int> a;
	bool minus = false;
	char c;
	for (int i = 0; i <= len; i++) {
		if (i != len)
			c = str.at(i);
		else
			c = '+';
		if (c == '-' || c == '+') {
			if (ret != 0) {
				if (minus)
					ret *= -1;
				a.push_back(ret);
			}
			if (c == '+')
				minus = false;
			else
				minus = true;
			ret = 0;
		}
			
		else {
			ret *= 10;
			ret += c - '0';
		}
	}
	int N = a.size(), ans = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] < 0) { 
			ret = -a[i];
			for (int j = i + 1; j < N; j++) {
				if (a[j] > 0) 
					ret += a[j];			
				else
					ret -= a[j];
				i++;
			}
			ans -= ret;
		}
		else
			ans += a[i];
	}
	cout << ans;
	return 0;
}