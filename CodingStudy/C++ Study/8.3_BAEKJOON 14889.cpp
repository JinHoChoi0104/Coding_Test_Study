// BAEKJOON 14889

#include<iostream>
#include<math.h>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

int score_arr[20][20];
int N, min_dif = 987654321;
bool check[20];

void calculateScore(vector<int> member, int total_mem) {
	memset(check, false, N);
	
	// 0번이 포함된 1팀 점수 계산
	int sum1 = 0;
	for (int i = 0; i < member.size() - 1; i++) {
		for (int j = i + 1; j < member.size(); j++)
			sum1 += score_arr[member[i]][member[j]];
		check[member[i]] = true; //이미 뽑힌 인원 체크
	}
	check[member.back()] = true;

	//Team without member0
	vector<int>member2;
	for (int i = 0; i < total_mem; i++) //아직 안 뽑힌 인원은 2팀으로
		if (!check[i])
			member2.push_back(i);

	// 0번이 없는 2팀 점수 계산
	int sum2 = 0;
	for (int i = 0; i < member2.size() - 1; i++) 
		for (int j = i + 1; j < member2.size(); j++) 
			sum2 += score_arr[member2[i]][member2[j]];

	min_dif = min(min_dif, abs(sum1 - sum2));
}
// 0번이 포함 된 1팀 먼저 선정 후
void findMember(vector<int> member, int last_mem, int total_mem, int need) { //뽑힌 인원, 마지막으로 뽑힌 인원, 전체 인원, 필요 잉원
	member.push_back(last_mem);
	if (need == 0) //All member1's team is choosen
		calculateScore(member, total_mem); //점수계산
	
	else  //not yet, go find other team members
		for (int i = last_mem + 1; i < total_mem; i++)
			findMember(member, i, total_mem, need - 1);
}
//10
// 1 4 ,5 6 7
// 4 1
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	int n = N / 2 - 1;//한 팀당 필요한 인원, 0번째는 1팀에 이미 들어가 있으니 -1

	for (int i = 0; i < N; i++) // i와 j, j와 i는 항상 같이 더해지므로 미리 더한다
		for (int j = 0; j < N; j++) {
			cin >> score_arr[i][j];
			if (i > j)
				score_arr[j][i] += score_arr[i][j];
		}

	vector<int> member;
	findMember(member, 0, N, n);

	cout << min_dif;
	return 0;
}