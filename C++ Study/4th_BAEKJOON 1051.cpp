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
	
	int ans = 0, size = min(N, M); //�� ���� ���� �� ª�� ���� ���簢���� ���� �� �ִ� ���� �ִ� ũ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = ans; k < size; k++) {
				if (i + k >= N || j + k >= M) //����� ��ǥ�� ����� pass
					break;
				if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k])
					ans = k; //4��ǥ Ȯ��
			}
		}
	}

	printf("%d",(ans+1)*(ans+1)); // ans + 1 ���ش�, ans�� ������ ��ǥ�� �������� �����Ƿ�!
	return 0;
}