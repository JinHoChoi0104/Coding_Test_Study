#include <iostream>

using namespace std;
/*
regex라는게 있다!!!
패턴이있는지 판별 할 때 쓰자!
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	int T;
	for (cin >> T; T-- > 0;) {
		cin >> str;
		str += '2';
		bool isP = true;
		int i = 0;
		while( i < str.size() - 1) {
			if (str.at(i++) == '0') { // 01인 경우
				if (str.at(i++) != '1') {
					isP = false;
					break;
				}
			}
			else { //1001인 경우
				if (str.at(i++) != '0') { //0이 2개는 무조건 있어야함
					isP = false;
					break;
				}
				if (str.at(i++) != '0') {
					isP = false;
					break;
				}
				while (str.at(i) == '0') 
					i++;	
				//1000111 '1' 1001 1 01 1101
				if (str.at(i++) != '1') { //1이 1개는 무조건 있어야함
					isP = false;
					break;
				}
				int k = 0;
				while (str.at(i) == '1') {
					i++;
					k++;
				}
				if (k == 0) //반복되는 1이 없는 경우 pass
					continue;
				
				if (str.at(i++) == '2') //반복되는 1이 나온 후 끝인 경우
					break;
				//반복되는 1이 나온 후 0이 나온 경우 ex) 100111110
				//그 다음 숫자가
				if (str.at(i) == '0') //00이면 1001일수도 있으니 앞으로 가서 체킹 
					i -= 2;
				else if (str.at(i) == '1') //01이면 또 하나의 페턴
					i++;
				else { //02이면 나올 수 없는 패턴
					isP = false;
					break;
				}
			}
		}
		if (isP)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}