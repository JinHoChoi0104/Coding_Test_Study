// BAEKJOON 11000
#include <iostream>
#include <vector>
using namespace std;

class lecture {
private:
	int S;
	int T;
public:
	lecture(int S, int T) {
		this->S = S;
		this->T = T;
	}
	void GetInfo();
	int GetS() { return S; };
	int GetT() { return T; };
};
void lecture::GetInfo() {
	cout << S << " " << T << endl;
};


void merge(vector<lecture>& arr, int left, int right) {
	vector<lecture> tmp (arr);

	int i, j, k;
	int mid = (left + right) / 2;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i].GetS() <= arr[j].GetS())
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	
	int a = i > mid ? j : i;
	while (k <= right) 
		tmp[k++] = arr[a++];
	
	for (int i = left; i <= right; i++) 
		arr[i] = tmp[i];
}
void mergeSort(vector<lecture>& arr, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right){
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, right);
	}
	
}

void bubbleSort(vector<lecture>& arr) {
	for(int i = 1; i < arr.size() ; i++)
		for (int j = 0; j < arr.size() - i; j++) {
			if (arr[j].GetS() > arr[j + 1].GetS())
				swap(arr[j], arr[j + 1]);
		}
}
int main()
{
	int N; // 1 <= N <= 200,000
	cin >> N; 

	vector <lecture> arr;
	int S, T;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		lecture in(S, T);
		arr.push_back(in);
	}

	// before assigning lecture to class room, sort list of lecture by it's 'S' (start time)
	// using MergeSort

	mergeSort(arr, 0, arr.size() - 1 );
//	bubbleSort(arr);
	//for (int i = 0; i < arr.size(); i++) 	arr[i].GetInfo();

	int result = 1;
	int min = 1000000001; 
	int check = 1; // when the previous class is over
	int index = 0;
	while (arr.size() > 0) {
		int cnt = index;
		for (int i = index; i < arr.size(); i++) {
			if (arr[i].GetS() >= check) {
				index = i;
				check = arr[index].GetT();
				break;
			}
			else
				cnt++;
		}
		
		if (cnt != arr.size()) 
			arr.erase(arr.begin() + index);	
		else { 
			check = 0;
			index = 0;
			result++;
		}
	}
	cout << result;
}