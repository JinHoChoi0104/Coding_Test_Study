#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	int index = str.at(0),len = str.length();
	string ans = "z";
	for (int i = 1; i < len; i++) 
		ans += "z";
	queue<int>q1;
	q1.push(0);
	for (int i = 1; i < len - 2; i++) { //제일 뒤의 두 알파벳을 제외하고, 제일 작은 알파벳을 찾는다
		if (index > str.at(i)) {
			while(!q1.empty())
				q1.pop();
			q1.push(i);
			index = str.at(i);
		}
		else if (index == str.at(i)) //제일 작은 것이 여러개인 경우
			q1.push(i);
	}
	while (!q1.empty()) {
		int cut1 = q1.front()+1;
		q1.pop();
		string str1 = str.substr(0, cut1); //cut1을 포함하여 앞을 자르고
		reverse(str1.begin(), str1.end()); //뒤집는다

		//2번째 자를 곳 탐색
		queue <int> q2;
		q2.push(cut1);
		index = str.at(cut1 );
		for (int i = cut1 + 1; i < len - 1; i++) { //제일 뒤의 알파벳 하나를 제외하고, 제일 작은 알파벳을 찾는다
			if (index > str.at(i)) {
				while (!q2.empty())
					q2.pop();
				q2.push(i);
				index = str.at(i);
			}
			else if (index == str.at(i)) //제일 작은 것이 여러개인 경우
				q2.push(i);
		}

		while (!q2.empty()) {
			int cut2 = q2.front()+1;
			q2.pop();
			string str2 = str.substr(cut1, cut2 - cut1); //cut1 뒤에서부터 cut2까지 자른다
			string str3 = str.substr(cut2); //나머지
			reverse(str2.begin(), str2.end()); //뒤집는다
			reverse(str3.begin(), str3.end());

			string tmp = str1; //3파트 합친다
			tmp += str2, tmp += str3;

			if (ans > tmp) //제일 작은 문자열을 찾는다
				ans = tmp;
		}
	}
	cout << ans;
	return 0;
}