#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class location {
public:
	int rank;
	int X;
	int transX;
	location(int _rank, int _X) {
		rank = _rank;
		X = _X;
	}
};
bool compareByX(location a, location b) {
	return a.X < b.X;
}
bool compareByRank(location a, location b) {
	return a.rank < b.rank;
}
int main(void) {
	int N;
	cin >> N;

	vector <location> arr;
	vector <int> xValue;
	int X;

	for (int i = 0; i < N; i++) {
		scanf("%d", &X);
		arr.push_back(location(i, X));
		xValue.push_back(X);
	}
	sort(xValue.begin(), xValue.end());
	xValue.erase(unique(xValue.begin(), xValue.end()), xValue.end());

	sort(arr.begin(), arr.end(), compareByX);
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].X == xValue[index]) 
			arr[i].transX = index;
		else
			arr[i].transX = ++index;	
	}
	sort(arr.begin(), arr.end(), compareByRank);

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i].transX);
	
	return 0;
}