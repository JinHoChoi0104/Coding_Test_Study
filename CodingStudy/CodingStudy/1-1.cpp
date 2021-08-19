#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
vector<vector<int>> arr(101, vector<int>(101));
int r = 3, c = 3; 

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second) //if the number of numbers is the same 
			return a.first > b.first;
		return a.second > b.second;
	}
};

void Rsorting() {
	vector<int>len; //remember row's length
	int max_c = c;
	for (int i = 1; i <= r; i++) {
		map<int, int>m;
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] == 0)
				continue;
			m[arr[i][j]]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
		for (auto it = m.begin(); it != m.end(); it++)
			pq.push(*it);
		int k = 1;
		while (!pq.empty()) {
			arr[i][k++] = pq.top().first, arr[i][k++] = pq.top().second;
			pq.pop();
			if (k == 101)
				break;
		}
		max_c = max(max_c, k - 1);
		len.push_back(k);
	}
	c = max_c;
	for (int i = 1; i <= r; i++) {
		for (int j = len[i-1]; j <= c; j++) {
			arr[i][j] = 0;
		}
	}	
}


void Csorting() {
	vector<int>len; //remember column's length
	int max_r = r;
	for (int i = 1; i <= c; i++) {
		map<int, int>m;
		for (int j = 1; j <= r; j++) {
			if (arr[j][i] == 0)
				continue;
			m[arr[j][i]]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
		for (auto it = m.begin(); it != m.end(); it++)
			pq.push(*it);
		int k = 1;
		while (!pq.empty()) {
			arr[k++][i] = pq.top().first, arr[k++][i] = pq.top().second;
			pq.pop();
			if (k == 101)
				break;
		}
		max_r = max(max_r, k - 1);
		len.push_back(k);
	}
	r = max_r;
	for (int i = 1; i <= c; i++) {
		for (int j = len[i - 1]; j <= r; j++) {
			arr[j][i] = 0;
		}
	}
}

void show() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int x, y, k, cnt = 0;
	cin >> x >> y >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	int& ret = arr[x][y];
	
	while (ret != k && cnt < 101) {
		cnt++;
		if (r >= c)
			Rsorting();
		else
			Csorting();
	}

	if (cnt == 101) //Time over, couldn't find answer
		cout << -1;
	else
		cout << cnt;
	return 0;
}