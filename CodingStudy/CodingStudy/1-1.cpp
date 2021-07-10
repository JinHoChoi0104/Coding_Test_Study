// BAEKJOON 1941
#include<iostream>
#include<vector>

using namespace std;

int arr[25];
bool board[5][5];
int sum = 0;

// 1. choose 7 people 25C7
// 2. eliminate under 3 S
// while doing 1, use cutting by using logic 2
// 3. check whether they are linked

void makeFalse(){
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			board[i][j] = false;
}

void DFS(int y, int x, int &cnt) {
	if (y > -1 && y < 5 && x > -1 && x < 5)	{
		if (board[y][x]) {
			cnt++;
			board[y][x] = false;

			DFS(y + 1, x, cnt);
			DFS(y, x + 1, cnt);
			DFS(y - 1, x, cnt);
			DFS(y, x - 1, cnt);
		}
	}
}

void isLinked(vector<int> member) {
	makeFalse();
	for (int i = 0; i < member.size(); i++) {
		board[member[i]/5][member[i]%5] = true;
	}

	int cnt = 0;
	DFS(member[0] / 5, member[0] % 5, cnt);
	if (cnt == 7)
		sum++;
}

void findMember(vector<int> member, int last_mem, int need, int isS) {
	member.push_back(last_mem);
	if (need == 0) {
		if(isS >= 4)
			isLinked(member);
	}
	else if(isS >= 4 - need){
		for (int i = last_mem + 1; i < 25; i++) {
			findMember(member, i, need - 1, isS + arr[i]);
		}
	}
}

int main(void) {
	char a;
	int index = 0;
	for (int i = 0; i < 29; i++) {
		scanf("%1c", &a);
		if (a == 'S')
			arr[index++] = 1;
		else if (a == 'Y')
			arr[index++] = 0;
	}

	vector<int> b;
	for (int i = 0; i < 25; i++) 
		findMember(b, i, 6, arr[i] );

	cout << sum;
}