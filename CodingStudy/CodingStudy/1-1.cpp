#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector < int > a(1000000);
vector < int > l; //save lis
vector < int > p(1000000); //save array num's position in lis

void lis() { // changed way of getting LIS and it's O(n log n )
	int index = 0, k = 0;
	l.push_back(a[0]), p[0] = 0;

	for (int i = 1; i < N; i++) {
		if (l[index] < a[i]) {
			l.push_back(a[i]);
			index++;
			p[i] = index;
		}
		else {
			k = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
			l[k] = a[i];
			p[i] = k;
		}
	}

	k = N;
	for (int i = index; i >= 0; i--) { //find out what's real LIS member
		while (1) {
			k--;
			if (p[k] == i) {
				l[i] = a[k];
				break;
			}
		}
	}

	printf("%d\n", index+1);
	for (int i = 0; i <= index; i++)
		printf("%d ", l[i]);
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	lis();

	return 0;
}