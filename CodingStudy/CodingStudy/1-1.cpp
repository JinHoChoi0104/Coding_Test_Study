#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector < vector <string> > byAge(201);
	int age;
	string name;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		byAge[age].push_back(name);
	}

	for (int i = 1; i < 201; i++) {
		if (byAge[i].size() > 0) {
			for (int j = 0; j < byAge[i].size(); j++) {
				cout << i << " " << byAge[i][j];
				printf("\n");
			}
		}
	}
	return 0;
}