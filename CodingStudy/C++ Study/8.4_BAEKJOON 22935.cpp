#include <iostream>
using namespace std;

/* 
1 <2 ~ 14> 15 <16 ~ 28> 29 <30 ~ 42> 43 <44 ~ 56>
1에서 28
29에서 56 이런식으로 주기가 28인 형태로 반복 된다.
28로 나눠서 나오는 나머지 값을 이용해 몇 번째의 수인지 파악한다.
이 때 주의할점은 28은 나눠서 나머지가 0인 것에 유념해야한다.
즉 나머지가
1 ~ 28이 아니라 1 ~ 27,0 의 형태다
*/ 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T, num;
	string str[30];
	for (int i = 1; i < 16; i++) {
		string tmp;
		int cnt = 0;
		num = i;
		while (num) {
			if (num % 2 == 0)
				tmp = "V" + tmp;
			else
				tmp = "딸기" + tmp;
			num /= 2, cnt++;
		} //2진법으로 환산 하면서 바로 딸기로 전환 후 저장
		while (cnt++ < 4) //나머지 빈 공간은 V로 채운다
			tmp = "V" + tmp;
		str[i] = tmp;
	}
	for (int i = 16; i < 30; i++) 
		str[i] = str[30 - i];
	
	str[0] = str[28]; //28번째의 수는 나머지가 0이므로
	
	for (cin >> T; T-- > 0; ) {
		cin >> num;
		cout << str[num % 28] <<"\n";
	}
	return 0;
}