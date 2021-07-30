#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

ll lpow(ll num, int k) {
	ll ans = 1;
	while (k--) ans *= num;
	return ans;
}

bool isAbigger(int* a, int* b, int a_len, int b_len) {
	if (a_len > b_len)
		return true;
	else if (a_len < b_len)
		return false;
	else
		for (int i = 0; i < a_len; i++)
			if (a[i] > b[i])
				return true;
			else if (b[i] > a[i])
				return false;
	return true;
}

ll getDigit(int* num, int len, int notation) {
	ll ans = 0;
	for (int i = 0; i < len; i++)
		ans += num[i] * lpow(notation, len - 1 - i);
	return ans;
}

void pone(int* big, int* small, int b_len, int s_len, int b_min, int s_min, bool isA) {
	ll b_num, s_num, ans;
	int A, B;
	bool isMulti = false;
	for (int i = b_min + 1; i <= 36; i++) {
		b_num = getDigit(big, b_len, i);
		for (int j = s_min + 1; j <= 36; j++) {
			if (i == j)
				continue;
			s_num = getDigit(small, s_len, j);
			if (b_num == s_num) {
				if (isMulti) {
					cout << "Multiple";
					return;
				}
				if (isA) 
					A = i, B = j;
				else 
					A = j, B = i;
				ans = b_num;
				isMulti = true;
			}
		}
	}
	if (isMulti)
		cout << ans << " " << A << " " << B;
	else
		cout << "Impossible";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a[71], b[71], a_len, b_len, a_min = 0, b_min = 0, tmp;
	string str;
	cin >> str;

	a_len = str.length();
	for (int i = 0; i < a_len; i++) {
		tmp = (int)str.at(i);
		if (48 <= tmp && tmp <= 57) // 0 ~ 9
			a[i] = tmp - 48;
		else  // a ~ z, a -> 10
			a[i] = (tmp - 87);
		a_min = max(a[i], a_min);
	}
	cin >> str;
	b_len = str.length();
	for (int i = 0; i < b_len; i++) {
		tmp = (int)str.at(i);
		if (48 <= tmp && tmp <= 57) // 0 ~ 9
			b[i] = tmp - 48;
		else // a ~ z, a - >10
			b[i] = tmp - 87;
		b_min = max(b[i], b_min);
	}

	bool isA = isAbigger(a, b, a_len, b_len);
	if(isA)
		pone(a, b, a_len, b_len, a_min, b_min, isA);
	else
		pone(b, a, b_len, a_len, b_min, a_min, isA);
	
	return 0;
}