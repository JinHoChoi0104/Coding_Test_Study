#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N;
	while (cin >> N) { //입력 들어올때까지 받기
		string str = "-";
		while( N-- > 0) { //N번 반복으로 칸토어 구한다
			string tmp = str;
			for (int i = 0; i < str.size(); i++)
				tmp += " ";
			str = tmp + str;
		}
		cout << str <<"\n";
	}
	return 0;
}