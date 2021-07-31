#include<iostream>
#include<vector>
#include<set>

using namespace std;

int M;
set <int> s;

void NM(int index, int cnt, vector<int> &a) {
	vector<int> arr(a);
	set<int>::iterator iter = s.begin();
	for (int i = 0; i < index; i++)
		iter++;
	arr.push_back(*iter);

	if (cnt == 0) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = index; i < s.size(); i++)
		NM(i, cnt - 1, arr);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, num;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		s.insert(num);
	}
	vector<int>arr;
	for (int i = 0; i < s.size(); i++)
		NM(i, M-1, arr);
	return 0;
}