#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct pos { int x, y; };
int main(void) {
	int N;
	scanf("%d", &N);
	char c;
	pos from, to;
	vector<pos> topping[4];// J, C, B, W;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &c);
			if (c == 'J')
				topping[0].push_back({ i, j });
			else if (c == 'C')
				topping[1].push_back({ i, j });
			else if (c == 'B')
				topping[2].push_back({ i, j });
			else if (c == 'W')
				topping[3].push_back({ i, j });
			else if (c == 'H')
				from.x = i, from.y = j;
			else if (c == '#')
				to.x = i, to.y = j;
		}
	}

	vector<int>m = { 0,1,2 };
	int job, len, min_len=987654321;
	
	for (int i = 0; i < 4; i++) {
		do {
			len = 0;
			len += abs(from.x - topping[i][m[0]].x);
			len += abs(from.y - topping[i][m[0]].y);
			for (int j = 0; j < 2; j++) {
				len += abs(topping[i][m[j]].x - topping[i][m[j+1]].x);
				len += abs(topping[i][m[j]].y - topping[i][m[j+1]].y);
			}
			len += abs(to.x - topping[i][m[2]].x);
			len += abs(to.y - topping[i][m[2]].y);
			if (min_len > len) {
				job = i;
				min_len=len;
			}
		} while (next_permutation(m.begin(), m.end()));
	}
	string str[4] = { "Assassin","Healer", "Mage", "Tanker" };
	cout << str[job];
	return 0;
}