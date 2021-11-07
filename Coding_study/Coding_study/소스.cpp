#include <iostream>
using namespace std;

void printArr(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << " " << arr[i];
	cout << endl;
}
/*
Selection Sort by using array data structure
*/
void SelectionSort(int* arr, int n) { // n : number of elements in array
	//start it's search(find smallest number) from second element to end element
	for (int i = 0; i < n - 1; i++) {
		int index = i; //index of element which smallest number will come
		int tmp = arr[i];
		for (int j = i + 1; j < n; j++) { //change to small number every time you find it
			if (arr[i] > arr[j]) {
				arr[i] = arr[j];
				index = j;
			}
		}
		arr[index] = tmp; //at last put original number(which was at index at first) to positon where smallest number was
		cout << " " << i + 1 << "th Selection Sort is done" << endl;
		printArr(arr, n);
	}
}

int main() {
	int arr[6] = { 5,3,2,9,1,4 };
	cout << " Input array" << endl;
	printArr(arr, 6);
	SelectionSort(arr, 6);
	return 0;
}