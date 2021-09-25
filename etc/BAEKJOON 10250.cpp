#include <iostream>
using namespace std;

class Test {
public:
	int H, W, N;
};
int main() {
	int T;
	cin >> T;

	Test* arr = new Test[T];

	for (int i = 0; i < T ; i++) 
		cin >> arr[i].H >> arr[i].W >> arr[i].N;

	float a, b;
	for (int i = 0; i < T; i++) {
		b = float (arr[i].N) / float(arr[i].H);
		if (int(b) - b != 0)// 소수점이면
			b = int(b) + 1;
		a = arr[i].N - arr[i].H * (b - 1);

		cout << a;
		cout.width(2); // 폭을 2로 지정
		cout.fill('0'); // 채움 문자는 '0'
		cout << b << endl;
	}

	return 0;
}