#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, arr[10002], lis_size;
vector<int> l; //save lis
vector<int> p(10002); //save array num's position in lis
void lis() {
	int index = 0, k = 0;
	l.push_back(arr[0]), p[0] = 0;
	for (int i = 1; i < N; i++) {
		if (l[index] < arr[i]) {
			l.push_back(arr[i]);
			index++;
			p[i] = index;
		}
		else {
			k = lower_bound(l.begin(), l.end(), arr[i]) - l.begin();
			l[k] = arr[i];
			p[i] = k;
		}
	}
	k = N, lis_size = index + 1;
	printf("%d\n", lis_size);
	for (int i = index; i >= 0; i--) { //find out real members of LIS
		while (1) {
			k--;
			if (p[k] == i) {
				l[i] = arr[k];
				break;
			}
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int num, a[10001];
	map <int, int> m; //key, value
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		a[num] = i;
		m.insert({ i, num });
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[i] = a[num];
	}

	lis();

	map <int, int> ans;
	for (int i = 0; i < lis_size; i++) {
		map<int, int>::iterator it = m.find(l[i]);
		ans[it->second]++;
	}
	for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++)
		printf("%d ", it->first);

	return 0;
}