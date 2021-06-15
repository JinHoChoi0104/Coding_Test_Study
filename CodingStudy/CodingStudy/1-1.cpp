// BAEKJOON 1342
// Permutation(¼ø¿­) algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Permutation(vector<char>& Array, vector<string>& Array2, int Start, int End)
{
	if (Start == End) // has been swapped
	{
		char a = 0, b = 0;
		int cnt = 0;
		for (const auto it : Array) //check whether it is Lucky String
		{
			b = it;
			if (a != b)
				cnt++;
			else
				break;
			a = b;
		}

		if (cnt == Array.size()) { //add all Lucky Strings to Array2
			string output(Array.begin(), Array.end()); //char vector to string
			Array2.push_back(output); //add new data at end of vector
		}
	}
	else
	{
		for (int i = Start; i <= End; ++i)
		{
			swap(Array[Start], Array[i]);
			Permutation(Array, Array2, Start + 1, End);
			swap(Array[Start], Array[i]);
		}
	}
}

int main()
{
	// convert a string to a vector of chars
	string S;
	cin >> S;
	vector<char> arr(S.begin(), S.end()); //vector list of input (char)
	vector<string> arr2; //Lucky Strings in ouput will be stroed in here(string)

	
	/* 2 ways of print vector
	1.
	for (int i = 0; i < arr.size(); i++) 
		cout << arr.at(i) << " ";
	
	2.
	for (const char& c : arr) 
		cout << c;
		
	3.
	for (const auto it : Array)
		cout << it;
		
	*/

	Permutation(arr, arr2, 0, arr.size() - 1);

	// remove duplicated elements from Array2
	sort(arr2.begin(), arr2.end());
	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

	cout << arr2.size();
}