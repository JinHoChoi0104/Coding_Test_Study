#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

int main(void) {
	int N, num, ans = 1087654321, num1, num2;
	scanf("%d", &N);
	priority_queue<int>p; //양수는 큰 수가 먼저 나오게 저장
	priority_queue<int, vector<int>, greater<>> m; // 음수는 작은 수가 먹저 나오게 저장
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num > 0)
			p.push(num);
		else
			m.push(num);
	}
	if (p.empty()) { //만약 큰 수가 없다면
		while (m.size() > 2)
			m.pop();
		num1 = m.top();
		m.pop();
		num2 = m.top();
		printf("%d %d", num1, num2); //음수 중 제일 작은 두 수 더한다
		return 0;
	}
	if (m.empty()) {
		while (p.size() > 2)
			p.pop();
		num1 = p.top();
		p.pop();
		num2 = p.top();
		printf("%d %d", num2, num1);
		return 0;
	}

	int p1 = p.top(), m1 = m.top(), pp[2], mm[2];
	pp[1] = p1, mm[1] = m1;
	p.pop(), m.pop();

	while (1) {
		if (abs(p1 + m1) < ans) {
			ans = abs(p1 + m1);
			num1 = m1, num2 = p1;
		}
		if (p1 > abs(m1)) { //절대 값이 더 큰 큐에서 팝을 해준다
			if (p.empty())
				break;
			p1 = p.top();
			p.pop();
		}
		else {
			if (m.empty())
				break;
			m1 = m.top();
			m.pop();
		}
	}
	if (p.size() > 0) { //양수가 남았을 경우 제일 작은 두 양수의 함이 작을 수도 있다 ex) -10000, 1, 2
		while (p.size() > 2)
			p.pop();
		if (p.size() == 2) {
			pp[1] = p.top();
			p.pop();
		}
		pp[0] = p.top();
		if (pp[0] + pp[1] < ans)
			num1 = pp[0], num2 = pp[1];
	}
	else if (m.size() > 0) {
		while (m.size() > 2)
			m.pop();
		if (m.size() == 2) {
			mm[1] = m.top();
			m.pop();
		}
		mm[0] = m.top();
		if (abs(mm[0] + mm[1]) < ans)
			num1 = mm[0], num2 = mm[1];
	}

	printf("%d %d", num1, num2);
	return 0;
}