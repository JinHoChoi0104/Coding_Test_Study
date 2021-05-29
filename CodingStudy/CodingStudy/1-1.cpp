#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string word;
	cin >> word;

	//단어 입력 string -> char array, 길이도!
	char* arr = new char[word.length() + 1];
	memmove(arr, word.c_str(), word.length());


	//2중 for문
	//1번째 a~z 아스키코드 활용
	//2번째 입력받은 단어에서 찾으면 break,else printout -1
	
	for (int i = 0; i < 26 ; i++) {
		for (int j = 0; j < word.length()+1; j++) {
			if (char(i + 97) == arr[j]) {
				cout << j << " ";
				break;
			}
			if (j == word.length())
				cout << "-1 ";
		}
	}

	return 0;
}