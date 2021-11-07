#include <iostream>
using namespace std;

void printArr(int* arr, int n) {
	for (int i = 0; i < n; i++) 
		cout << " " << arr[i];
	cout << endl;
}
/*
insertion sort by using array data structure
which means you have to consider data between two changing data
*/
void insertionSort(int* arr, int n) { // n : number of elements in array
	//start it's insertion from second element => consider first element as already sorted
	for (int i = 1; i < n; i++) {
		int tmp = arr[i]; //el
		int index = i;	
		while (arr[index - 1] > tmp) { //if element at front is larger than tmp
			arr[index] = arr[index - 1]; //then move it to back 
			index--;
			if (index == 0) //there is no more element to check!
				break;
		}
		arr[index] = tmp;
		cout <<" "<< i << "th Insertion Sort is done" << endl;
		printArr(arr, n);
	}
}

int main() {
	int arr[6] = { 5,3,2,9,1,4 };
	cout << " Input array" << endl;
	printArr(arr, 6);
	insertionSort(arr, 6);
	return 0;
}