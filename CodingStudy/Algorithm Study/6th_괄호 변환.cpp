#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string p) {
	string answer = "";

	int len = p.size();
	int l, r;
	stack<char>s;

	for (int i = 0; i < len; i++) {
		l = 0, r = 0;
		cout << p[i];
		if (p[i] == '(') {
			s.push('(');
			l++;
			while (l != r) {
				i++;
				if (p[i] == '(') {
					l++;
					s.push('(');
				}
				else {
					r++;
					s.push(')');
				}
			}
			string str = "";
			stack<char>tmp;
			while (!s.empty()) {
				if (s.top() == ')')
					tmp.push(')');
				else {
					if (tmp.empty()) {
						str = "";
						while (l-- > 0)
							str = str + '(';
						while (r-- > 0)
							str = str + ')';
						break;
					}
					else
						tmp.pop();
				}
				str = s.top() + str;
				s.pop();
			}
			answer = answer + str;
		}
		else {
			r++;
			while (l != r) {
				i++;
				if (p[i] == '(') {
					l++;
				}
				else {
					r++;
				}
			}
			string str = "";
			while (l-- > 0)
				str = str + '(';

			while (r-- > 0) {
				str = str + ')';

				answer = answer + str;
			}
		}
		return answer;
	}