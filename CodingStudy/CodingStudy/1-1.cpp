#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N, cnt;
	cin >> N;
	cnt = N;

	for (int i = 0; i < N; i++) {
		string input; 
		cin >> input;

		// string to char vector
		vector <char> strToChar(input.begin(), input.end()); 
		
		int index = 0;
		while (index < strToChar.size() - 1) {
			if (strToChar[index] == strToChar[index + 1]) // exclude continuous duplicate characters
				strToChar.erase(strToChar.begin() + index);
			else
				index++;
		}

		bool isAlpha[26] = { false };
		for (int i = 0; i < strToChar.size(); i++) { // In ASCII a = 97
			if (!isAlpha[(int)strToChar[i] - 97]) // if the character has never appeared
				isAlpha[(int)strToChar[i] - 97] = true;
			else { // if the character has been appeared befor
				cnt--;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}