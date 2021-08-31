#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
set <int> s; //센서들이 같은 위치에 있는건 의미가 없으므로 하나로 친다
//거리 순으로 정렬도 된다 set은
/*
position: 1    3     6   7     9
distance:    2    3    1    2
*/
int main() {
	scanf("%d %d", &N, &K); 
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		s.insert(num);
	}

	//제일 먼 곳들간의 거리를 구한다.
	auto it = s.end();
	it--;
	int total_dis = *it - *s.begin(); 

	//센서들간의 거리를 구한다
	vector<int>dis;
	int pre = *s.begin(), pos;
	for (auto it = ++s.begin(); it != s.end(); it++) {
		pos = *it;
		dis.push_back(pos - pre);
		pre = pos;
	}

	//센서들간의 거리를 내림차순으로 정렬한다
	sort(dis.begin(), dis.end(), greater<>());

	//센서들간의 거리 중 제일 큰 K - 1개를 구한 후
	//총 거리에서 빼준다
	for (int i = 0; i < K - 1; i++) {
		if (i == dis.size())
			break;
		total_dis -= dis[i];
	}
	
	//답 출력
	printf("%d", total_dis);
	return 0;
}