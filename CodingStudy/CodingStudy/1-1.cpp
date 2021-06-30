#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {	
	int N;
	scanf("%d", &N);
	
	vector < vector <string> > byLength(50);
	string word;

	for (int i = 0; i < N; i++) {
		cin >> word;
		byLength[word.length() - 1].push_back(word);	
	}
		
	for (int i = 0; i < 50; i++) {
		if (byLength[i].size() > 0) {			
			sort(byLength[i].begin(), byLength[i].end());		
			byLength[i].erase(unique(byLength[i].begin(), byLength[i].end()), byLength[i].end());
				
			for (int j = 0; j < byLength[i].size(); j++)
				cout << byLength[i][j] << endl;		
		}
	}
	return 0;
}
