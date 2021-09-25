#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int arr[50][50];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%1d", &arr[i][j]);
	
	int ans = 0, size = min(N, M); //두 변의 길이 중 짧은 것이 정사각형이 가질 수 있는 변의 최대 크기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = ans; k < size; k++) {
				if (i + k >= N || j + k >= M) //사이즈가 좌표를 벗어나면 pass
					break;
				if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k])
					ans = k; //4좌표 확인
			}
		}
	}

	printf("%d",(ans+1)*(ans+1)); // ans + 1 해준다, ans는 마지막 좌표는 포함하지 않으므로!
	return 0;
}