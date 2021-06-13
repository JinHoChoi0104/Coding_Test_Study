// BAEKJOON 1342
// Permutation(순열) algorithm
// Reference: https://ansohxxn.github.io/algorithm/combination/

#include <iostream>
#include <vector>

using namespace std;

void Combination(vector<char> arr, vector<char> comb, int index, int depth)
{
	if (depth == comb.size())
	{
		for (int i = 0; i < comb.size(); i++)
			cout << comb[i] << " ";
		cout << endl;

		return;
	}
	else
	{
		for (int i = index; i < arr.size(); i++)
		{
			comb[depth] = arr[i];
			Combination(arr, comb, i + 1, depth + 1);
		}
	}
}

int main()
{
	vector<char> vec = { 'a', 'b', 'c', 'd', 'e' };  // n = 5

	int r = 3;
	vector<char> comb(r);

	Combination(vec, comb, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기 

	return 0;
}