#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare1(const pair<long long, long long>& a, const pair<long long, long long>& b) {
	return a.first < b.first;
}
bool compare2(const pair<long long, long long>& a, const pair<long long, long long>& b) {
	return a.second < b.second;
}
int main(void) {
	int N = 0;
	scanf("%d", &N);
	vector<pair <long long , long long >> arr(N);

	for (int i = 0; i < N; i++) 
		scanf("%d %d", &arr[i].first, &arr[i].second);

	sort(arr.begin(), arr.end(), compare1);
	stable_sort(arr.begin(), arr.end(), compare2);

	int index = 0, cnt = 0;
	long long end_time = 0;
	while (index < N) {
		if (end_time <= arr[index].first) {
			cnt++;
			end_time = arr[index].second;
		}
		index++;
	}
	cout << cnt;
	return 0;
}