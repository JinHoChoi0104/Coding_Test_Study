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
		else //�ǿ����ڴ� �� stack�� �־�д�
			s.push(arr[str.at(i) - 'A']);
	}

	cout << fixed; // �Ҽ������� �Ƚ�
	cout.precision(2); // �Ҽ��� �ڸ���
	cout << s.top();

	return 0;
}