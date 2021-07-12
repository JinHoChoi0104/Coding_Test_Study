// BAEKJOON 11000
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


bool compare(const pair<int, int>& a, const pair <int, int>& b) {
	//if(a.first!=b.first)
		return a.first < b.first;
	//return a.second < b.second;
}

int main() {
	int N; // 1 <= N <= 200,000
	scanf("%d", &N);

	vector <pair <int, int>> arr;
	int S, T;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &S, &T);
		arr.push_back(pair<int, int>(S, T));
	}
	sort(arr.begin(), arr.end(), compare);
	// before assigning lecture to class room, sort list of lecture by it's 'S' (start time)
	// using Sort
	
	multiset<int> class_end_time; //to check when lecture was over per classes
	class_end_time.insert(arr[0].second);
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].first >= *class_end_time.begin()) { //if fastest starting lecture starts after fastest ending class end
			class_end_time.erase(class_end_time.begin());
			class_end_time.insert(arr[i].second);
		}
		else
			class_end_time.insert(arr[i].second);
	}
	
	printf("%d", class_end_time.size());
}