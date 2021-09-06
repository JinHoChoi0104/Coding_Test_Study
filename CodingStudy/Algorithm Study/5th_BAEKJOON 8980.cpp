#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

struct box { int from, to, num; };

bool compare(const box& a, const box& b) {
	if (a.to == b.to)
		return a.from > b.from;
	return a.to < b.to;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<box>v;
	vector<int> truck(2001, 0); //i번째 마을을 지나갈때 가지고 있는 박스의 수
	int N, C, M, from, to, num, volume, ans = 0, tmp = 0, index = 0;


	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> num;
		v.push_back({ from, to, num });
	}

	sort(v.begin(), v.end(), compare);
	/* 도착지가 가까운 곳 우선 정렬 
	도착지가 같은 곳은 도착지에서 가까운 곳이 앞으로 오게 정렬한다
	도착지와 같을 수록 운반 가능성이 크기 때문이다
	*/
	for (int i = 2; i <= N; i++) { //목표 도착지
		while (i > v[index].to) { //입력 받은 정보들에서 목표 도착지로 이동한다
			index++;
			if (index == M) //배열 범위제한
				break;
		}
		if (index == M)
			break;
		while (i == v[index].to) {
			volume = 0;
			/*
			1번 마을에서 4번 마을로 갈 때
			4번 마을에서는 어짜피 짐을 내리니까
			truck에는 1번에서 3번 마을 까지 짐을 싣고 가는 정보만 저장해주면 된다.
			*/
			for (int j = v[index].from; j < i; j++)
				volume = max(volume, truck[j]);
			/*
			volume = 박스를 실어서 지나가야 되는 마을들 중에서 
			가장 박스를 많이 싣고 지나는 양
			C - volume = 트럭이 싣고 갈 수 있는 최대 박스 수
			*/
			if (C - volume > v[index].num) { //실을 수 있는 박스 보다 마을에 박스양이 더 적을 때
				for (int j = v[index].from; j < i; j++)
					truck[j] += v[index].num;
				ans += v[index].num;
			}
			else { //실을 수 있는 박스보다 마을에 박스가 더 많을 때
				for (int j = v[index].from; j < i; j++)
					truck[j] += C - volume;
				ans += C - volume;
				break;
				/*
				도착지와 가까운곳을 기준으로도 정렬한 이유이다
				트럭에 박스를 실을 칸이 없다는 것은 도착지에서 더 먼 곳도 당연히
				실어서 올 수 없다는 뜻이다.
				*/
			}
			index++;
			if (index == M)
				break;
		}
		if (index == M)
			break;
	}

	cout << ans;

	return 0;
}