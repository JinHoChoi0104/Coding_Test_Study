#include <iostream>

void rangeBubbleSort(int* arr[], int N, int a, int b) { 
	int tmp;
	for (int i = a + 1; i < b + 1; i++) {
		for (int j = a; j < N - i; j++)
			if (arr[j][1] > arr[j + 1][1]) {
				tmp = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = tmp;

				tmp = arr[j][1];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][1] = tmp;
			}
	}
}

void bubbleSort(int *arr[], int N) {
	int tmp;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - i; j++)
			if (arr[j][0] > arr[j + 1][0]) {
				tmp = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = tmp;


				tmp = arr[j][1];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][1] = tmp;
			}
	}
	
	int index = 0;
	int cnt = 1;
	while (index < N - 1) {
		if (arr[index][0] == arr[index + 1][0]) {
			for (int i = index; i < N-1; i++) {
				if (arr[i][0] == arr[i + 1][0])
					cnt++;
				else
					break;
			}
			rangeBubbleSort(arr, N, index, cnt);
			index += cnt;
			cnt = 1;
		}
		else						
			index++;
	}
}

void mergeSort(int* arr[], int left, int right, int index);
void merge(int *arr[], int left, int right, int index) { //only executed when there are more than two datas in array
	int mid = (left + right) / 2;
	int* tmp0 = new int[right - left + 1];
	int* tmp1 = new int[right - left + 1];
	int i = left, j = mid + 1;
	int k = 0; //for tmp[]
	while (i <= mid && j <= right) {
		if (arr[i][index] < arr[j][index]) {
			tmp0[k] = arr[i][0];
			tmp1[k++] = arr[i++][1];
		}
		else {
			tmp0[k] = arr[j][0];
			tmp1[k++] = arr[j++][1];
		}
	}

	int a = i > mid ? j : i;
	while (k <= right - left) {
		tmp0[k] = arr[a][0];
		tmp1[k++] = arr[a++][1];
	}


	for (int l = left; l <= right; l++) { 
		arr[l][0] = tmp0[l - left];
		arr[l][1] = tmp1[l - left];
	}
}
void mergeSort(int *arr[], int left, int right, int index) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid, index);
		mergeSort(arr, mid + 1, right, index);
		merge(arr, left, right, index);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	int** pos = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		pos[i] = (int*)malloc(sizeof(int) * 2);
		for (int j = 0; j < 2; j++)
			scanf("%d", &pos[i][j]);
	}

	mergeSort(pos, 0, N - 1, 0);
	
	int index = 0;
	int cnt = 1;
	while (index < N - 1) {
		if (pos[index][0] == pos[index + 1][0]) {
			for (int i = index; i < N - 1; i++) {
				if (pos[i][0] == pos[i + 1][0])
					cnt++;
				else
					break;
			}
			mergeSort(pos, index, index+ cnt -1, 1);
			index += cnt;
			cnt = 1;
		}
		else
			index++;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++)
			printf("%d ", pos[i][j]);
		printf("\n");
	}
	
	return 0;
}