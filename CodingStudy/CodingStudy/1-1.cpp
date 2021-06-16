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
		arr[i].GetInfo();
	}
}