#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> edge[10001];
vector<char> v1;
vector<char> v2;
vector<string> tmp1;
vector<string> tmp2;

void get1(string str, int index, int cnt) {
	if (str.size() == cnt) {
		tmp1.push_back(str);
		return;
	}
	if (index == v1.size())
		return;
	for (int i = index; i < v1.size(); i++)
		get1(str + v1[i], i + 1, cnt);
}
void get2(string str, int index, int cnt) {
	if (str.size() == cnt) {
		tmp2.push_back(str);
		return;
	}
	if (index == v2.size())
		return;
	for (int i = index; i < v2.size(); i++)
		get2(str + v2[i], i + 1, cnt);
}
int main() {
	int L, C, num;
	char c;
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			v1.push_back(c);
		else
			v2.push_back(c);
	}

	/* 
	1 <= 모음, 2<= 자음, 자음 + 모음 = L
	1 <= L - 자음  
	2 < = 자음 <= L - 1
	*/
	vector<string> ans;
	for (int i = 2; i < L; i++) {
		// 모음 수: L - i , 자음 수: i
		get1("", 0, L - i); // L-i개로 만들 수 있는 모음 추출
		get2("", 0, i); // 자음 추출
		for (int p = 0; p < tmp1.size(); p++) { //가능한 모든 모음과
			for (int q = 0; q < tmp2.size(); q++) { //가능한 모든 자음을 
				string str = tmp1[p] + tmp2[q];  //다 합쳐본다
				vector<char>tmp; 
				for (int k = 0; k < str.size(); k++)
					tmp.push_back(str[k]);
				sort(tmp.begin(), tmp.end());
				str = "";
				for (int k = 0; k < tmp.size(); k++)
					str = str + tmp[k];
				ans.push_back(str); //string내 알파벳을 정렬후 정답에 저장
			}
		}
		tmp1.clear(), tmp2.clear();
	}
	sort(ans.begin(), ans.end()); //정답 string들을 알파벳순으로 정렬한다
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it <<"\n";
	return 0;
}