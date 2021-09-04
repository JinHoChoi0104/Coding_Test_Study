#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<int> arr;
	vector<int> tree(100000);
	stack<int>s;
	int num, index = 1;

	while (cin >> num) {
		arr.push_back(num);
	}
	int tmp1, tmp2;
	tree[0] = 987654321;
	tree[index] = arr[0];
	s.push(arr[0]);
	for (int i = 1; i < arr.size(); i++) {
		cout << index<<" "<<tree[index] << endl;
		if (tree[index] > arr[i]) {
			tree[index * 2] = arr[i];
			index *= 2;
			s.push(arr[i]);
		}
		else {
		//	cout << index;
			while (tree[index/2]<arr[i]) {
				//cout << "a";
				index /= 2;
			}
			tree[index*2 + 1] = arr[i];
			index= index*2+1;

		}
	}

	return 0;
}