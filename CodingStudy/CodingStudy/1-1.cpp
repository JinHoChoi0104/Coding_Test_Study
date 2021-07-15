#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct consult{int sum, n;};
int sum_max = 0, N = 0;
vector <pair<int, int>> arr;
queue <consult> con_arr;

void consulting(){	
	consult con;
	int endT = 0, sum = 0;

	while (!con_arr.empty()) {
		endT = con_arr.front().n;
		sum = con_arr.front().sum;
		con_arr.pop();
		
		if (sum > sum_max)
			sum_max = sum;
		if (endT < N) 
			for (int i = endT; i < endT + arr[endT].first && i < N; i++) 
				if (arr[i].first + i <= N) //if in range
					con_arr.push({ arr[i].second + sum, arr[i].first + i });//if in range
	}
}

int main(void) {
	int T, P;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &T, &P);
		arr.push_back(pair<int, int> (T, P));
	}

	int index = 0;
	while (arr[index].first + index > N) {
		index++;
		if (index == N)
			break;
	}
	if (index < N) {
		con_arr.push({ 0, index });
		consulting();
	}
	cout << sum_max;
	return 0;
}