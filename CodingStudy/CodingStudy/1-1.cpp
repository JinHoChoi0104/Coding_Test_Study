#include <iostream>
#include <map>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	map<int, int> sum; //position, sum of a[n] + a[n+1]
	int T, K, index, min_num, size;
	scanf("%d", &T);
	int a[500];
	list<pair<int,int>> l;
	while (T--) {
		scanf("%d", & K);
		for (int i = 0; i < K; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < K - 1; i++) {
			l.push_back(make_pair(a[i], a[i] + a[i + 1]));
		}
		l.push_back(make_pair(a[K - 1], 10000));
		size = K;
		int total = 0;
		while (size-- > 1) {
			min_num = 10000, index = 0;
			int k = 0;
			for (auto it = l.begin(); it != l.end(); it++) {
				//cout << it->first << " ";
				if (min_num > it->second) {
					min_num = it->second;
					index = k;
				}
				k++;
			}
			cout << endl;
			//		cout << "?? " << index << endl ;
			auto it = l.begin();
			for (int i = 0; i <= index + 1; i++) {

				it++;
			}
			int next;
			if (it == l.end()) {
				next = 10000;
				it--;
			}
			else {
				next = it->first;
				it--;
			}
			it--;
			int new_file = it->second;
			l.insert(it, make_pair(new_file, new_file + next));

			it++;
			auto it2 = it;
			it--;
			l.erase(it2);
			auto it3 = it;
			it--;
			l.erase(it3);

			int before = 0;
			if (it == l.begin()) {
				before = 0;
			}
			else {
				it--;
				before = it->first;
				l.insert(it, make_pair(before, before + new_file));
			//	it--;
				l.erase(it);
			}
			cout << size << endl;
		//	for (auto it = l.begin(); it != l.end(); it++)	printf("%3d ", it->first);
			cout << new_file;
			//for (auto it = l.begin(); it != l.end(); it++)	printf("%3d ", it->second);
			cout << endl;
			total += new_file;
		}
		cout << total << endl;
	}
	return 0;
}