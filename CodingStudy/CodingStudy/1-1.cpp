#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, rate[4];
	scanf("%d", &N);
	for (int i = 0; i < 4; i++)
		scanf("%d", &rate[i]);
	for (int i = 0; i < 4; i++)
		rate[i]--;

	vector<int> arr;
	char c;
	for (int i = 0; i < N; i++) {
		scanf(" %c", &c);
		if (c == 'B')
			arr.push_back(0);
		else if (c == 'S')
			arr.push_back(1);
		else if (c == 'G')
			arr.push_back(2);
		else if (c == 'P')
			arr.push_back(3);
		else
			arr.push_back(4);
	}

	int sum = 0, a1, a2 = 0, tmp;
	if (arr[0] < 4)
		a1 = rate[arr[0]], sum = a1;
	else
		a1 = rate[3] + 1, sum = a1;
	for (int i = 1; i < N; i++) {
		if (arr[i] < 4)
			a2 = rate[arr[i]] - a1;
		else
			a2 = rate[3] + 1;
		sum += a2;
		a1 = a2;
	}

	printf("%d", sum);

	return 0;
}