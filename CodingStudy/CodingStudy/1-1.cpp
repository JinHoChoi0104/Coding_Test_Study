#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector < int > a(1000);
vector < int > l; //save lds

void lds() { // simply change direction of LIS
	int index = 0;
	l.push_back(a[N-1]);

	for (int i = N-2; i >=0 ; i--) {
		if (l[index] < a[i]) {
			l.push_back(a[i]);
			index++;
		}
		else 
			l[lower_bound(l.begin(), l.end(), a[i]) - l.begin()] = a[i];
	}
	
	printf("%d", index+1);
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	lds();

	return 0;
}