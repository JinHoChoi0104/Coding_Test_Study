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
//vector<lecture> tmp;

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
	//	tmp.push_back(in);
	}

	// before assigning lecture to class room, sort list of lecture by it's 'S' (start time)
	// using MergeSort
	//for (int i = 0; i < arr.size(); i++) 	arr[i].GetInfo();

	mergeSort(arr, 0, arr.size() - 1 );

	int result = 1;
	int min = 1000000001; 
	int check = 1; // when the previous class is over
	while (1) {
		//min = arr.front().GetS();
		int index = 0;
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i].GetS() == check) {
				min = 1000000001;
				index = i;
				//check = arr[i].GetT(); 
				break;
			}

			else if (min > arr[i].GetS() && check <= arr[i].GetS()) {
				min = arr[i].GetS();
				index = i;
				//check = arr[i].GetT();

			}
			else
				cnt++;
		}
		check = arr[index].GetT();
		if (cnt != arr.size()) {
		//	cout << "erase! :";
		//	arr[index].GetInfo();
			arr.erase(arr.begin() + index);
	//		cout << "a: " << arr.size() << endl;
		}
		else {
		//	cout << "b: " << cnt << endl;
			min = 1000000001; 
			check = 0;
			result++;
		}
	//	cout << "==== lab =====" << endl;
	
		if (arr.size() == 0)
			break;
	}
	cout << result;
}