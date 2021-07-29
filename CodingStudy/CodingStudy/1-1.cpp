#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector < vector<int> > a(1001, vector<int>(1001));

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	int len1, len2, N;
	string str;
	char c1[1000], c2[1000];

	cin >> str;
	len1 = str.size(); // vertical
	c1[0] = '0', a[0][0] = 0;
	for (int i = 0; i < len1; i++) {
		c1[i + 1] = str.at(i);
		a[i][0] = 0;
	}

	cin >> str;
	len2 = str.size(); //horizontal
	c2[0] = '0';
	for (int i = 0; i < len2; i++){
		c2[i + 1] = str.at(i);
		a[0][i] = 0;
	}
	
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (c1[i] == c2[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		}
	}

	cout << a[len1][len2];

	return 0;
}