#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	string str;
	cin >> str;
	vector<double>arr(N);
	stack<double>s;
	for (int i = 0; i < N;i++) 
		cin >> arr[i];
	
	double a, b;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str.at(i) == '*') {
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			a *= b;
			s.push(a);
		}
		else if (str.at(i) == '/') {
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			a /= b;
			s.push(a);
		}
		else if (str.at(i) == '+') {
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			a += b;
			s.push(a);
		}
		else if (str.at(i) == '-') {
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			a -= b;
			s.push(a);
		}
		else //피연산자는 다 stack에 넣어둔다
			s.push(arr[str.at(i) - 'A']);
	}

	cout << fixed; // 소수점으로 픽스
	cout.precision(2); // 소수점 자릿수
	cout << s.top();

	return 0;
}