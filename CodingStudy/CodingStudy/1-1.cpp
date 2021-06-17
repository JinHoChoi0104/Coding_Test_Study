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
	void SetInfo(int _S, int _T);
	void GetInfo(); 
	int GetS() { return S; };
	int GetT() { return T; };
};

void lecture::SetInfo(int _S, int _T) {
	S = _S;
	T = _T;
}
void lecture::GetInfo() {
	cout << S << " " << T << endl;
};

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

	for (int i = 0; i < arr.size(); i++) {
	//	arr[i].GetInfo();
	}
	int result = 0;
	int min = 1000000001; // arr.front().GetS();;//arr.front().GetS();
	int check = 0; // when the previous class is over
	while (1) {
		//min = arr.front().GetS();
		int index = 0;
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (min > arr[i].GetS() && check < arr[i].GetS()) {
				min = arr[i].GetS();
				index = i;
				check = arr[i].GetT();
			}
			else
				cnt++;
		}
		if (cnt != arr.size())
			arr.erase(arr.begin() + index);
		else {
			min = 1000000001; // arr.front().GetS();
			check = 0;
			result++;
		}

		
	//	cout << min << endl;
		if (arr.size() == 0)
			break;
	}
	cout << result;
}