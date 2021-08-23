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
	
	// 0���� ���Ե� 1�� ���� ���
	int sum1 = 0;
	for (int i = 0; i < member.size() - 1; i++) {
		for (int j = i + 1; j < member.size(); j++)
			sum1 += score_arr[member[i]][member[j]];
		check[member[i]] = true; //�̹� ���� �ο� üũ
	}
	check[member.back()] = true;

	//Team without member0
	vector<int>member2;
	for (int i = 0; i < total_mem; i++) //���� �� ���� �ο��� 2������
		if (!check[i])
			member2.push_back(i);

	// 0���� ���� 2�� ���� ���
	int sum2 = 0;
	for (int i = 0; i < member2.size() - 1; i++) 
		for (int j = i + 1; j < member2.size(); j++) 
			sum2 += score_arr[member2[i]][member2[j]];

	min_dif = min(min_dif, abs(sum1 - sum2));
}
// 0���� ���� �� 1�� ���� ���� ��
void findMember(vector<int> member, int last_mem, int total_mem, int need) { //���� �ο�, ���������� ���� �ο�, ��ü �ο�, �ʿ� �׿�
	member.push_back(last_mem);
	if (need == 0) //All member1's team is choosen
		calculateScore(member, total_mem); //�������
	
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
	int n = N / 2 - 1;//�� ���� �ʿ��� �ο�, 0��°�� 1���� �̹� �� ������ -1

	for (int i = 0; i < N; i++) // i�� j, j�� i�� �׻� ���� �������Ƿ� �̸� ���Ѵ�
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