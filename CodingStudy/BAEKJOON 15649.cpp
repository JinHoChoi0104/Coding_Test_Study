#include <iostream>
using namespace std;

/*
백트래킹 (Backtracking) 알고리즘
가능한 모든 방법을 탐색한다
*/

int Factorial(int num) {
	if (num == 0)
		num = 1;
	for (int i = num - 1; i > 0; i--)
		num *= i;
	return num;
}

int main() {
	int n, m;
	cin >> n >> m;
	int* arr = new int[m];
	bool* index = new bool[n + 1];

	for (int i = 0; i < n + 1; i++) {
		index[i] = true;
	}
	for (int i = 0; i < m; i++) {
		arr[i] = i + 1;
		cout << arr[i] << " ";
		index[i + 1] = false;
	}
	cout << "\n";

	int cnt = 1;
	int lim = Factorial(n) / Factorial(n - m);
	int rot, pos;

	while (lim > cnt) {
		rot = 0; //스텍에서 더 큰 수를 찾았는지 여부
		pos = 0; //바꿀 위치
		for (int i = m - 1; i > -1; i--) { // <------ 탐색
			for (int j = arr[i]; j < n; j++) {
				if (index[j + 1] == true) { //스텍에 더 큰 수가 있다
					index[arr[i]] = true; // i에 있는걸 스텍으로
					arr[i] = j + 1; //더 큰 수를 스텍에서 i자리로
					index[j + 1] = false; // index 수정해주기
					rot = 1;
					pos = i; //어디서 위치 교환 났는지 저장
					i = -1;
					break;
				}
			}

			if (rot == 0) { // 스텍에 더 큰 수가 없다		
				for (int j = m - 1; j > i; j--) {  // <---- 방향 탐색
					if (arr[i] < arr[j]) {// 내 뒤에 나보다 큰수가 있는지 본다
						//여러개가 있다면 작은걸로 근데 작은게 뒤에 있겠지?
						index[arr[i]] = true; // i에 있는걸 스텍으로
						arr[i] = arr[j]; //더 큰 수를 스텍에서 i자리로
						arr[j] = 0; // 원래 자리에 있던건 0으로
						pos = i;
						i = -1;
						break;
					}
				}
			}
			if (i == -1) { //앞에서 교환이 일어났다면
				for (int j = pos + 1; j < m; j++) { // 그 뒤에 값들 다 스택으로
					index[arr[j]] = true;
					arr[j] = 0;
				}
				for (int p = pos + 1; p < m; p++) { // 그 뒤에 스텍에서 다기 가져오기
					for (int q = 1; q < n + 1; q++) {
						if (index[q] == true) {
							arr[p] = q;
							index[q] = false;
							break;
						}
					}
				}
			}
		}

		cnt++;
		for (int i = 0; i < m; i++) 
			cout << arr[i] << " ";
		cout << "\n";
	}

	return 0;
}