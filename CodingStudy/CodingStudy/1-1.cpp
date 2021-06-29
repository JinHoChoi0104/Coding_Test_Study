#include <iostream>
#include <vector>
#include <string>
using namespace std;

void mergeByLength(vector <string> &arr, int left, int right) { //only executed when there are more than two datas in array
	int mid = (left + right) / 2;
	string* tmp = new string[right - left + 1];
	int i = left, j = mid + 1;
	int k = 0; //for tmp[]

	while (i <= mid && j <= right) {
		if (arr[i].length() < arr[j].length()) 
			tmp[k++] = arr[i++];
		else 
			tmp[k++] = arr[j++];	
	}

	int a = i > mid ? j : i;
	while (k <= right - left) 
		tmp[k++] = arr[a++];
	
	for (int l = left; l <= right; l++) 
		arr[l]= tmp[l - left];
}

void mergeByDictionary(vector <string> &arr, int left, int right) { //only executed when there are more than two datas in array
	int mid = (left + right) / 2;
	string* tmp = new string[right - left + 1];
	int i = left, j = mid + 1;
	int k = 0; //for tmp[]

	while (i <= mid && j <= right) {
		if (arr[i].compare( arr[j]) == -1) 
			tmp[k++] = arr[i++];
		else 
			tmp[k++] = arr[j++];	
	}

	int a = i > mid ? j : i;
	while (k <= right - left) 
		tmp[k++] = arr[a++];
	
	for (int l = left; l <= right; l++) 
		arr[l]= tmp[l - left];
}

void mergeSort(vector<string> &arr, int left, int right, int index) { //index 0: merge by length, index 1: merge by dictionary
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid, index);
		mergeSort(arr, mid + 1, right, index);
		if (index == 0)
			mergeByLength(arr, left, right);
		else
			mergeByDictionary(arr, left, right);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	vector <string> arr;

	
	string str;
	for (int i = 0; i < N; i++) {	
		cin >> str;
		arr.push_back(str);
	}

	mergeSort(arr, 0, N - 1, 0);
	
	
	int index = 0;
	int cnt = 0;

	while (index < arr.size() - 1) {
		while (1) {
			if (arr[index].length() == arr[index + 1].length()) { 
				if (arr[index] == arr[index + 1])
					arr.erase(arr.begin() + index + 1);
				else {
					cnt++;
					index++; 
				}
			}
			else
				break;
			if (index + 1 == arr.size())
				break;
		}
		mergeSort(arr, index-cnt, index, 1);	
		
		index++;
		cnt = 0; 
	}
	

	for (int i = 0; i < arr.size(); i++) 
		cout << arr[i] << endl;
	
	return 0;
}