#include <stdio.h>
#include <stdlib.h>

void Star(int **arr, int x, int y, int n);
void Stamp(int** arr, int size);

int main() {
	int size;
	scanf("%d", &size);

	/*2차원배열 동적할당*/
	int** arr = (int**)malloc(sizeof(int*) * size);	
	for (int i = 0; i < size; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * size);
	}

	Star(arr, 0, 0, size);
	Stamp(arr, size);

	return 0;
}

void Star(int** arr, int x, int y, int n) {
	int p= x, q = y;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if(i!=1 || j!=1)
				if(n>3)
					Star(arr, x + i * n / 3,y + j * n / 3, n / 3);
				else
					arr[x + i][y + j] = 1;
}
void Stamp(int** arr, int size) {
	int x = 0, y = 0;
	while (y < size) {
		if (arr[x][y] == 1) {

			printf("*");

		}
		else
			printf(" ");

		if (x < size - 1)
			x++;
		else {
			x = 0;
			y++;
			printf("\n");
		}
		if (x == size || y == size)
			break;
	}
}