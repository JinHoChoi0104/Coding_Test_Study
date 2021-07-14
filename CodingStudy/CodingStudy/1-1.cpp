//BAEKJOON 1672
#include<iostream>
using namespace std;

int main(void) {
	char c[1000000];
	const char* board[] = { "ACAG",
	"CGTA",
	"ATCG",
	"GAGT" };
	int N, a, b;
	
	scanf("%d%s",&N, c);
	while (N > 1) {
		switch (c[N - 1]) {
		case 'A':
			a = 0;
			break;
		case 'G':
			a = 1;
			break;
		case 'C':
			a = 2;
			break;
		case 'T':
			a = 3;
			break;
		}
		switch (c[N - 2]) {
		case 'A':
			b = 0;
			break;
		case 'G':
			b = 1;
			break;
		case 'C':
			b = 2;
			break;
		case 'T':
			b = 3;
			break;
		}
		c[N - 2] = board[a][b];
		N--;
	}
	
	printf("%c", c[0]);
	return 0;
}