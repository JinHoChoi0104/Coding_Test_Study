#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N, S, M, num;
	scanf("%d %d %d", &N, &S, &M);
	map<int,int>m;
	m[S]++;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		map<int,int>tmp; //i번째 단계에서 가질 수 있는 볼륨의 경우의 수
		for (auto it = m.begin(); it != m.end(); it++) {
			int volume = it->first;
			if (volume + num <= M) //범위 안에 들어가면 카운트 해준다
				tmp[volume + num] += it->second;
			if (volume - num >= 0)
				tmp[volume - num] += it->second;
		}
		m.swap(tmp);
	}
	if (m.empty()) //연주 할 수 없는 경우
		printf("-1");
	else { //map은 value에 따라 정렬 되므로 제일 뒤에 값 반환해준다
		auto it = m.end();
		it--;
		printf("%d", it->first);
	}
	return 0;
}