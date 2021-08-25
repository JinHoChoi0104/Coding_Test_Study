#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int>arr(100);
map<int, long long>m; //index까지 계산해서 얻은 값, 그 값의 갯수
int N;
long long cnt = 0;
void DFS(int index) { //계산해야될 곳의 인덱스
	if(index == N-1) { //모든 계산을 마쳤을 때
		for (auto it = m.begin(); it != m.end(); it++)
			if (it->first == arr[N - 1])
				cnt+=it->second; //카운트 한다
		return;
	}
	int a, b;
	map<int, long long>tmp; //임시 저장소
	for (auto it = m.begin(); it != m.end(); it++) {
		a = it -> first + arr[index], b = it -> first - arr[index];
		if (a >= 0 && a <= 20)
			tmp[a] += it -> second;
		if (b >= 0 && b <= 20)
			tmp[b] += it -> second;
	}
	m.swap(tmp); //스왑해준다
	DFS(index + 1);
}

int main(void) {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);

	m[arr[0]]++;
	DFS(1);

	printf("%lld", cnt);
	return 0;
}