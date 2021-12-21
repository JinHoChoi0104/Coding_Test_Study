1#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, n;
	cin >> a >> b >> n;
	/*
	분자가 분모보다 큰 경우 실행
	이렇게 해주지 않을 경우, 입력이
	(3, 4, 1), (7, 4, 1) 일 때 값이 같아야함에도 달라진다.
	for문이 돌아가는 횟수는 소수점의 자릿수만큼 돌아가는데
	분자가 분모보다 클경우 몫을 한 번 구하는 나눠주는 과정을 거치기 때문이다.
	*/
	if (a > b)
		a %= b;
	for (int i = 0; i < n; i++) { //구해야 하는 소수점의 자릿수만큼 반복
		a %= b; //몫은 결과값으로, 나머지는 결과값의 다음 소수점을 구하는데 쓰인다 
		a *= 10; //정수값으로 만들어준다
	}
	cout << a / b; //나누어진 몫을 반환해야하므로
	return 0;
}