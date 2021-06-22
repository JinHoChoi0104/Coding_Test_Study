// BAEKJOON 1157

#include <iostream>
#include <cstring>

using namespace std;

int main() {

	string word;
	cin >> word;
	char* arr = new char[word.length() + 1]; // string to char array
	memmove(arr, word.c_str(), word.length());

	int alpha[26] = {0};
	for (int i = 0; i < word.length(); i++) {
		if ((int)arr[i] > 96) // if small , a = 97
			alpha[(int)arr[i] - 97]++;
		else // if capital a = 65
			alpha[(int)arr[i] - 65]++;
	}

	int max = 0, max_cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (max_cnt < alpha[i]) {
			max_cnt = alpha[i];
			max = i;
		}
		else if (max_cnt == alpha[i]) 
			max = -2;
		
	}

	cout << char(max + 65);
}