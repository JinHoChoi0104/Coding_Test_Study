#include <iostream>
using namespace std;
int main(){
	int num, arr[6] = {1,1,2,2,2,8};
	for (int i = 0; i < 6; i++) {
		cin >> num;
		arr[i] -= num;
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	return 0;
} 