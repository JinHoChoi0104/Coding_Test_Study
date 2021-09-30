#include <iostream>
#include <string>
using namespace std;

bool gotAnswer = false;
int N;
string ans;

/*
N 길이의 좋은 수열이 있을 때
뒤에 한 숫자를 붙혀서
N + 1 길이의 새로운 수열이 나쁜 수열이 되기 위해서는
마지막 숫자를 포함하여 패턴이 생겨야한다

이를 이용해 길이 1에서 시작해서 목표 길이까지 하나씩 
늘려가며 나쁜수열 여부를 확인한다.
*/

bool isBad(string str) { //나쁜 수열인지 확인
	int len = str.size(); 
	for (int i = 1; i <= len / 2; i++) { //수열의 가능한 길이는 전체길이의 반
		if (str.substr(len - i, i) == str.substr(len - i * 2, i))
			return true;
	}
	return false;
}

void makeNum(string str) { //가능한 숫자 조합을 만든다
	int len = str.size();
	if (len == N) { //목표 길이면 멈추고 답을 반환
		gotAnswer = true;
		ans = str;
		return;
	}
	for (int i = 1; i <= 3; i++) { //재귀를 통해 DFS마냥 구하므로 오름차순으로 살필 수 있다
		string tmp = str + to_string(i);
		if (isBad(tmp))
			continue;
		if (gotAnswer) //답 구했으면 STOP
			break;
		makeNum(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	string tmp = "1";
	makeNum(tmp);
	cout << ans;
	return 0;
}