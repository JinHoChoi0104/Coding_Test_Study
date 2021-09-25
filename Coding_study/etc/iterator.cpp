#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	vector<int>a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(7);

	vector<int>::iterator it;
	for (it = a.begin(); it != a.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	int* it2;
	it2 = &a.front();
	for (int i=0; i < a.size(); i++) {
		cout << *it2 << " ";
		it2++;
	}
	return 0;
}