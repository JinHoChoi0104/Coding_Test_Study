#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct jo { 
	string f, e; 
	int OS; // If OS doesn't recognize extension, In other words if e is not included in m 
};

vector <jo > arr; //filename
map <string, int>m; //extension

bool compare(const jo& a, const jo& b) {
	if (a.f != b.f)	//if file names are different
		return a.f < b.f;
	else if (a.OS != b.OS) 
		return a.OS > b.OS;
	else 
		return a.e < b.e;
}
int main(void) {
	int N, M, index;
	string str;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		cin >> str;
		index = str.find('.');
		arr.push_back({ str.substr(0, index), str.substr(index + 1), 0 });
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		m[str]++;
	}

	for (int i = 0; i < N; i++)	
		if (m.find(arr[i].e) != m.end()) //if e exitst in m
			arr[i].OS = 1;
	
	sort(arr.begin(), arr.end(), compare);
	
	for (int i = 0; i < N; i++) {
		cout << arr[i].f << "." << arr[i].e;
		printf("\n");
	}
	return 0;
}