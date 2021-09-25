#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int case_n;
	cin >> case_n;

	int** arr = (int**)malloc(sizeof(int*) * case_n);

	int num;
	for (int i = 0; i < case_n; i++) {
		cin >> num;
		arr[i] = (int*)malloc(sizeof(int) * (num+1));
		arr[i][0] = num;
		for (int j = 1; j < num+1; j++) {
			cin >> arr[i][j];
		}
	}


	float sum = 0;
	int cnt = 0;


	for (int i = 0; i < case_n; i++){
		for (int j = 1; j < arr[i][0] + 1; j++) {
			sum += arr[i][j];
		}
		sum /= float(arr[i][0]);
		for (int j = 1; j < arr[i][0] + 1; j++) {
			arr[i][j] > sum ? cnt++ : NULL;
		}
		cout << fixed; //소수점 자리 표현
		cout.precision(3);
		cout << cnt /float(arr[i][0]) * 100 << "%" << endl;
		cnt = 0;
		sum = 0;
	}
	
	return 0;
}