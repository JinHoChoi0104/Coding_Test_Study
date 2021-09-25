#include <iostream>
#include <vector>
using namespace std;

vector<int>arr;

void findroot(int l, int r) { //루트를 찾는다
	if (r < l)
		return;
	int i;
	for (i = l + 1; i <= r; i++) //루트보다 큰 수를 찾고 그 수를 기준으로 좌측 우측 자식 노드탐색
		if (arr[i] > arr[l]) break;

	findroot(l + 1, i - 1); //왼쪽 자식 노드 탐색
	findroot(i, r); //오른쪽 자식 노드 탐색
	printf("%d\n", arr[l]); //후위순위 결과 출력
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	while (cin >> num) //ctrl + z 나올때까지 입력 받는다
		arr.push_back(num);

	findroot(0, arr.size()-1);

	return 0;
}