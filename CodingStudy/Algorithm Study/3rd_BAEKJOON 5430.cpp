#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int T, N, num;
	string str,str2;
	char c;

	for (cin >> T; T > 0; T--) { //테케 입력받기
		cin >> str >> N;
		deque <int > dq;
		for (int i = 0; i < N; i++) {
			cin >> c >> num; //문자 숫자 번갈아 가며 입력 받기
			dq.push_back(num);
		}
		cin >> str2; //마지막 문자 ] 입력 받기
		//숫자가 없어서 입력이 []인 경우를 위해 string으로 입력받기
		
		int len = str.length(), front = 1; //front 는 뒤집어져있는지 여부 확인 용
		bool iserror = false; // 에러인지 확인용
		for (int i = 0; i < len; i++) {
			if (str.at(i) == 'R')
				front *= -1;
			else {
				if (dq.empty()) {
					iserror = true;
					break;
				}
				if (front == 1)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (iserror)
			cout << "error\n";
		else { //에러가 아니면 출력
			cout << "[";
			while (!dq.empty()) {
				if (front == 1) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				else {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}