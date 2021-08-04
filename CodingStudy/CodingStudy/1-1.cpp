#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int N, arr[10000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);
			
	int index = N;
	for (int i = N - 1; i > 0; i--) { //searching from back
		if (arr[i - 1] < arr[i])
			continue;
		index = i - 1; //find first higer num
		break;
	}
	if (index == N) { // if numbers are in ascending order
		printf("-1");
		return 0;
	}
	// Among numbers behind index, find highest number but smaller than index number 
	int target = lower_bound(arr + (index + 1), arr + N, arr[index]) - arr - 1;
	
	int ret = arr[index]; // Switch index with target number
	arr[index] = arr[target], arr[target] = ret;

	// With numbers behind the index, sort by descending order
	sort(arr + (index + 1), arr + N, greater<>());

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}