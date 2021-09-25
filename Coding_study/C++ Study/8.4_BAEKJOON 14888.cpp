#include<iostream>

using namespace std;

int max_num = -100000000;
int min_num = 100000000;
int A[11]; //input number

void DFS(int num, int plus, int minus, int multiple, int divide, int n) { // 2<= N <= 11, n = N, N-1, ... , 0
	if (n == -1) { // n는 전체 연산의 횟수가 저장 돼 있었다
		if (num > max_num)
			max_num = num;
		if (num < min_num)
			min_num = num;
	}
	else {
		if (plus > 0)
			DFS(num + A[n], plus - 1, minus, multiple, divide, n - 1);
		if (minus > 0)
			DFS(num - A[n], plus, minus - 1, multiple, divide, n - 1);
		if (multiple > 0)
			DFS(num * A[n], plus, minus, multiple - 1, divide, n - 1);
		if (divide > 0)
			DFS(num / A[n], plus, minus, multiple, divide - 1, n - 1);
	}
}

int main(void) {
	int N;
	cin >> N;
	for (int i = N - 1; i > -1; i--)
		cin >> A[i];
	int arr[4]; // plus, minus, multiple, divide
	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	DFS(A[N - 1], arr[0], arr[1], arr[2], arr[3], N - 2);
	cout << max_num << endl;
	cout << min_num << endl;
}