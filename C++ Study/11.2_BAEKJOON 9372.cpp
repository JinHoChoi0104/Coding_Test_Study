#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int t, N, M, a, b;
	for (cin >> t; t-- > 0;) {
		cin >> N >> M;
		//��� ���� �湮�� �� �� �ִٴ� ���� �����Ѵ� => ���д�Ʈ���� ���� �� �� �ִ�.
		for (int i = 0; i < M; i++) 
			cin >> a >> b;
		//���ؾ� �ϴ� ���� ���� - 1�ϸ� �ȴ�.
		cout << N - 1 << "\n";
	}

	return 0;
}