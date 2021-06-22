#include <iostream>
#include <queue>
#include <set>
using namespace std;

//BAEKJOON 1697

int HideAndSick(int pos, int K) { // pos: position where SooBin is placed now
	set<int> visited; //don't visit places you've alrady been
	visited.insert(pos);

	int depth = 0;
	queue<pair<int, int>>arr;
	arr.push({ pos ,depth });
	

	while (K != pos) {
		pos = arr.front().first;
		depth = arr.front().second;
		arr.pop();
		if (pos >= K) {
			if (visited.find(pos - 1) == visited.end()) { //set.find return index (iterator), if there is no element then return set.end()	
				arr.push({ pos - 1,depth + 1 });
				visited.insert(pos - 1);
			}
		}
		else {
			if (K == pos * 2) {
				if (visited.find(pos * 2) == visited.end()) {
					arr.push({ pos * 2,depth + 1 });
					visited.insert(pos * 2);
				}
			}
			else {
				if (visited.find(pos * 2) == visited.end()) { 	
					arr.push({ pos * 2,depth + 1 });
					visited.insert(pos * 2);
				}
				if (visited.find(pos - 1) == visited.end()) {
					arr.push({ pos - 1,depth + 1 });
					visited.insert(pos - 1);
				}
				if (visited.find(pos + 1) == visited.end()) {
					arr.push({ pos + 1,depth + 1 });
					visited.insert(pos + 1);
				}
			}
		}
	}

	return depth;
}


int main()
{
	int N, K;
	cin >> N >> K;

	cout << HideAndSick(N, K);
}