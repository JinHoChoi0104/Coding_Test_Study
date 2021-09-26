#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str, ans = "";
	getline(cin, str);

	int index = 0, len = str.size();
	str = str + " ";

	while (index < len) { //태그
		if (str[index] == '<') {
			while (str[index] != '>') 
				cout << str[index++];
			cout << str[index++];
		}
		else { //단어
			stack<char>tmp; //단어 임시 저장
			while (str[index] != ' ' && str[index] != '<') 
				tmp.push( str[index++]);
			while (!tmp.empty()) { //뒤집어서 출력 된다
				cout << tmp.top();
				tmp.pop();
			}
			//다음 문자가 태그가 아니고, 끝 단어가 아니면 공백 붙여준다
			if (str[index] == ' ' && index != len)
				cout << str[index++];
			else if(str[index] == ' ')
				index++;
		}
	}

	return 0;
}