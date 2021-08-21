#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num, pre=0, max_len = 1, len = 0;
	bool upward = true;
	for (cin >> T; T-- > 0; ) {
		cin >> num;
		if (pre < num) { //위로 간다
			if (upward) //위로 가능 중이였다
				len++;
			else { //내려 가는 중이였으므로 등산 끝
				max_len = max_len > len ? max_len : len;
				upward = true; //다시 올라갈 준비
				len = 2; //이전꺼랑 지금꺼 합쳐서 길이 2
			}
		}
		else if (pre > num) {
			if (upward) //올라가는 중이였으면 이제 내려간다
				upward = false;			
			len++;
		}
		else { //이전과 높이가 같다면
			max_len = max_len > len ? max_len : len;
			upward = true; //다시 올라갈 준비
			len = 1; //이전꺼는 포함 안 하고 이번꺼만 포함
		}
		pre = num;
	}
	max_len = max_len > len ? max_len : len;
	cout << max_len;
	return 0;
}