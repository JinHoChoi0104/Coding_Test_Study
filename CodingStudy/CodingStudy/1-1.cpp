#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	freopen("input.txt", "r", stdin);
	int n, num, index = 1, k=0;
	char c[200000];
	bool isS = true;
	scanf("%d", &n);
	stack <int> s;

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (!isS)
			continue;
		if (!s.empty()) {
			if (s.top() == num) {
				s.pop();
				c[k++] = '-';
			}
			else if (num >= index) {
				while (s.top() != num) {
					s.push(index++);
					c[k++] = '+';
				}
				s.pop();
				c[k++] = '-';
			}
			else
				isS = false;
		}
		else {
			if (num >= index) {
				s.push(index++);
				c[k++] = '+';
				while (s.top() != num) {
					s.push(index++);
					c[k++] = '+';
				}
				s.pop();
				c[k++] = '-';
			}
			else
				isS = false;
		}
	}
	if (!isS)
		printf("NO");
	else
		for (int i = 0; i < k; i++)
			printf("%c\n", c[i]);
	return 0;
}