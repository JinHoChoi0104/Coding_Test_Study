#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark { int x, y; };
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int num, ans = 0, ret;
	vector<shark>arr;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			if (num == 1) {
				arr.push_back({ i, j });
			}
		}
	num = arr.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ret = max(N, M);
			for (int k = 0; k < num; k++) {
				ret = min(ret, max(abs(arr[k].x - i), abs(arr[k].y - j)));
			}
			ans = max(ans, ret);
		}
	}
	
	printf("%d", ans);
	return 0;
}