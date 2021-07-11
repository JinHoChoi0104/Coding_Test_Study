// BAEKJOON 11000
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(const pair<int, int>& a, const pair <int, int>& b) {
	return a.first < b.first;
}

int main() {
	int N; // 1 <= N <= 200,000
	scanf ("%d", &N);

	vector <pair <int, int>> arr;
	int S, T;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &S, &T);
		arr.push_back(pair<int , int>(S, T));
	}
	sort(arr.begin(), arr.end(), compare);
	// before assigning lecture to class room, sort list of lecture by it's 'S' (start time)
	// using Sort

	int result = 0; // how many class?
	int check = 1; // when the previous class is over
	
	while (!arr.empty()) {
		for (int i = 0; i < arr.size(); i++) {	
			if (arr[i].first >= check) {
				
				check = arr[i].second;
				arr.erase(arr.begin() + i);
				i--;
			}		
		}
		result++;
		check = 1;
	}

	printf("%d", result);
}