#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	//a=97
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {

	}

	string word;
	cin >> word;
	char* arr = new char[word.length() + 1]; // string to char array
	memmove(arr, word.c_str(), word.length());
	for (int i = 0; i < word.length() -1 ; i++) {
		if(arr[i] == arr[i+1])
	}
	/*
	size_t pos;
	while (1) {
		pos = str.find("c=");
		if (pos == string::npos)
			break;
		str.replace(pos, 2, " ");
	}*/
	return 0;
}