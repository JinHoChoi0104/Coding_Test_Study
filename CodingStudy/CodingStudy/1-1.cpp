#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N, C, M, from, to, num;
	scanf("%d %d %d", &N, &C, &M);
	map<int, int>m[2001]; //어디로, 얼만큼
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &num);
		m[from][to] = num;
	}
	int total = 0;
	int volume = C; //현재 차가 실을 수 있는 박스의 수
	map <int, int>car; //to, num
	for (int i = 1; i <= N; i++) {
		int drop = car[i];
		car[i] = 0;
		volume += drop;
		total += drop;
		//cout << total << endl;
		for (auto it = m[i].begin(); it != m[i].end(); it++) {
			if (it->second <= volume) {
				car[it->first] += it->second;
				volume -= it->second;
			}
			else {
				car[it->first] += volume;
				volume = 0;
				break;
			}
		}
	}
	printf("%d", total);
	return 0;
}