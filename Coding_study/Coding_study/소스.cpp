#include <iostream>
using namespace std;
int main(){
	int n, num, arr[16][16];
	for (int i = 1; i <= 15; i++) {
		arr[1][i] = i + 1;
		arr[i][1] = i + 1;
	}
	for (int i = 2; i <= 15; i++) 
		for (int j = 2; j <= 15; j++) 
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> num;

	cout << arr[n][n] << " " << n * n;
	return 0;
} 