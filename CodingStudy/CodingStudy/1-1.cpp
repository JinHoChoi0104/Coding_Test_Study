#include <iostream>
#include <algorithm>
using namespace std;
int arr[501], sum = 0, W, H;
void left(int to) { //  0 ~ index
	int tallest = arr[to - 1], index = to - 1;
	bool isPole = false;
	for (int i = to - 2; i > -1; i--) {
		if (arr[i] >= tallest) {
			tallest = arr[i];
			index = i;
			isPole = true;
		}
		if (arr[i] > arr[i + 1])
			isPole = true;
	}
	if (!isPole)
		return;
	for (int i = index + 1; i < to; i++) 
		sum += (tallest - arr[i]);
	if (index != 0)
		left(index);
}
void right(int to) { //index ~ end
	int tallest = arr[to + 1], index = to + 1;
	bool isPole = false;
	for (int i = to + 2; i < W; i++) {
		if (arr[i] >= tallest) {
			tallest = arr[i];
			index = i;
			isPole = true;
		}
		if (arr[i-1] < arr[i])
			isPole = true;
	}
	if (!isPole)
		return;
	for (int i = to + 1; i < index; i++) 
		sum += (tallest - arr[i]);
	if (index != W-1)
		right(index);
}
int main() {
//	freopen("input.txt", "r", stdin);
	int tallest = 0, index = 0;
	scanf("%d %d", &H, &W);
	for (int i = 0; i < W; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > tallest) {
			tallest = arr[i];
			index = i;
		}
	}
	left(index);
	right(index);
	printf("%d", sum);
	return 0;
}