#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
set <int> s; 
//Since sensors with same position means nothing, treat them as if only one sensor
//And to get distance arrange them into a line by ascending order 

int main() {
	scanf("%d %d", &N, &K); 
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		s.insert(num);
	}

	//get total ditance = distance between closest sensor and most far sensor 
	auto it = s.end();
	it--;
	int total_dis = *it - *s.begin(); 

	//get distance with nearby sensors
	vector<int>dis;
	int pre = *s.begin(), pos;
	for (auto it = ++s.begin(); it != s.end(); it++) {
		pos = *it;
		dis.push_back(pos - pre);
		pre = pos;
	}

	//sort distances by descending order 
	sort(dis.begin(), dis.end(), greater<>());

	//get K - 1 longest distance between sensors
	//take them out from total distance
	for (int i = 0; i < K - 1; i++) {
		if (i == dis.size())
			break;
		total_dis -= dis[i];
	}
	
	//print out answer
	printf("%d", total_dis);
	return 0;
}