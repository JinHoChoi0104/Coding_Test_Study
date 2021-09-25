#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark { int x, y, z; };
struct shark2 { int y, z; }; //weak shark
vector<shark>arr;
int N, min_surivor;
bool compare(const shark &a, const shark &b) {
	if (a.x == b.x && a.y == b.y) 
		return a.z < b.z;	
	else if (a.x == b.x) 
		return a.y < b.y;
	else
		return a.x < b.x;
}
bool compare2(const shark2& a, const shark2& b) {
	if (a.y == b.y)
		return a.z < b.z;
	else
		return a.y < b.y;
}
void carnival(vector<shark2>remain, int e1, int e2, int index) { //index of sharks staring to eat
	if (e2 != -1) { //eat 2nd shark
		remain.erase(remain.begin() + e2);
	}
	if (e1 != -1){ //eat 1st shark
		remain.erase(remain.begin() + e1);
	}

	for (int i = index; i < N; i++) {
		sort(remain.begin(), remain.end(), compare2);
		shark& ret = arr[i];
		vector<int> tmp;
		remain.push_back({ ret.y , ret.z});
		for (int j = 0; j < remain.size() - 1; j++) {
			if (remain[j].y <= ret.y && remain[j].z <= ret.z) {
				//cout << "j: " << j << " : " << remain[j].y << " " << remain[j].z << endl;
				tmp.push_back(j); //save index of weaker shark above remain sharks
			}
		}
		if (tmp.size() < 3) {
			for (int j = tmp.size() - 1; j >= 0; j--) { //erase from back
				//cout << remain[tmp[j]].y << " " << remain[tmp[j]].z << endl;
				remain.erase(remain.begin() + tmp[j]);
			}
//			sort(remain.begin(), remain.end(), compare2);
		}
		else {//is there strongest sharks in remain?
			int len = tmp.size();
			shark2& ret1 = remain[tmp[len-1]]; //last input is eater shark
			shark2& ret2 = remain[tmp[len-2]];
			bool isbig1 = true;
			bool isbig2 = true;

			for (int j = len - 3; j >= 0; j--) {
				if (remain[tmp[j]].z > ret1.z)
					isbig1 = false;
				if (remain[tmp[j]].z > ret2.z)
					isbig2 = false;
				if (!isbig1 && !isbig2)
					break;
			}
			if (isbig1 && isbig2) { //eat both strongest sharks
				remain.erase(remain.begin() + tmp[len - 2]);
				remain.erase(remain.begin() + tmp[len - 1]);
			}
			else if (isbig1) { //eat 1 strongest shark and eat 1 shark in random
				remain.erase(remain.begin() + tmp[len - 1]);
				for (int j = 0; j < len - 1; j++) {
				//	cout << tmp[j] << endl;
					carnival(remain, tmp[j], -1, i + 1);
				}
				return;
			}
			else { //eat 2 sharks in random
				for (int p = 0; p < len - 1; p++)
					for (int q = p + 1; q < len; q++)
						carnival(remain, tmp[p], tmp[q], i + 1);
				return;
			}
		}
	}
//	for (int i = 0; i < remain.size(); i++)
//		cout << remain[i].y << " " << remain[i].z << endl;
//	cout << endl;
	min_surivor = min(min_surivor, (int)remain.size());
}

int main() {
	int x, y ,z;
	scanf("%d", &N);
	min_surivor = N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		arr.push_back({ x,y,z });
	}
	sort(arr.begin(), arr.end(), compare);

	vector<shark2>remain; //weak sharks, that haven't been eaten yet 
	remain.push_back({ arr[0].y, arr[0].z });
	carnival(remain, -1, -1, 1);
	printf("%d", min_surivor);
	return 0;
}