#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edge[10001];

int main() {
	int V, E, a, b, c;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({ b,c });
	}
	return 0;
}