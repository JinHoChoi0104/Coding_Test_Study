// BAEKJOON 1342
// Permutation(순열) algorithm
// Reference: https://ansohxxn.github.io/algorithm/combination/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/* 순열 알고리즘 */
void Permutation(vector<int>& Array, int Start, int End)
{
	if (Start == End)
	{
		for (const auto it : Array)
		{
			cout << it << " ";
		}
		cout << endl;


	}
	else
	{
		for (int i = Start; i <= End; ++i)
		{
			swap(Array[Start], Array[i]);
			Permutation(Array, Start + 1, End);
			swap(Array[Start], Array[i]);
		}
	}
}

int main()
{
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(2);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr.at(i) << " ";
	}

	Permutation(arr, 0, arr.size()-1);
}