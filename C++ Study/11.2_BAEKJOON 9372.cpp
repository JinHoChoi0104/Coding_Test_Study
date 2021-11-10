#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int t, N, M, a, b;
	for (cin >> t; t-- > 0;) {
		cin >> N >> M;
		//모든 노드는 방문을 할 수 있다는 것을 보장한다 => 스패닝트리를 형성 할 수 있다.
		for (int i = 0; i < M; i++) 
			cin >> a >> b;
		//구해야 하는 값은 노드수 - 1하면 된다.
		cout << N - 1 << "\n";
	}

	return 0;
}