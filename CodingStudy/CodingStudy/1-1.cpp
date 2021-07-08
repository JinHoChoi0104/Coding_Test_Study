// BAEKJOON 14889

#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int score_arr[20][20];
int min_difference = 100000;

bool check[20] = { false };
void makeFalse(bool* check) {
	for (int i = 0; i < 20; i++)
		check[i] = false;
}
void calculateScore(vector<int> member, int total_mem) {
	makeFalse(check);
	//Team with member0
	int sum1 = 0;
	for (int i = 0; i < member.size() - 1; i++) {
		for (int j = i + 1; j < member.size(); j++) {
			sum1 += score_arr[member[i]][member[j]];
			sum1 += score_arr[member[j]][member[i]];
		}
	}
	for (int i = 0; i < member.size(); i++) {
		check[member[i]] = true;
	}

	//Team without member0
	vector<int>member2;
	for (int i = 0; i < total_mem; i++) {
		if (!check[i])
			member2.push_back(i);
	}

	int sum2 = 0;
	for (int i = 0; i < member2.size()-1; i++) {
		for (int j = i+1; j < member2.size(); j++) {
			sum2 += score_arr[member2[i]][member2[j]];
			sum2 += score_arr[member2[j]][member2[i]];
		}
	}

	if (min_difference > abs(sum1 - sum2))
		min_difference = abs(sum1 - sum2);
}

void findMember(vector<int> member, int last_mem , int total_mem, int need) {
	member.push_back(last_mem);
	if (need == 0) {
		calculateScore(member, total_mem);
	}
	else {
		for (int i = last_mem + 1; i < total_mem; i++) 
			findMember(member, i, total_mem, need - 1);
	}
}

int main(void) {
	int N; 
	cin >> N;
	int n = N / 2 - 1;//Number of people required per team

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> score_arr[i][j];

	vector<int> member;
	findMember(member, 0, N, n);

	cout << min_difference;
	return 0;
}