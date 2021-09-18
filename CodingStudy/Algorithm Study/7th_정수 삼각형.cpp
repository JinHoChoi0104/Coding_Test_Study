#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int n = triangle.size();
	//디피 - 바텀 업
	for (int i = n - 2; i >= 0; i--) //밑에서 2번째 줄 부터 시작
		for (int j = 0; j <= i; j++)
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
	//아래 근접한 두 수 중 큰 값을 선택해서 더해주면서 올라간다.

	return triangle[0][0]; //가장 꼭대기에 최댓값 저장 된다.
}