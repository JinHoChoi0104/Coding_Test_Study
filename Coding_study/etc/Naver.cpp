#include <string>
#include <vector>

using namespace std;
int N;
vector<int> answer;
int getPrime(int n) { //아라토네스 활용!
	int i;
	for (i = 2; i <= n; i++)
		if (n % i == 0)
			return i;
	return i;
}

void dividing(int index, int num) { //0, 12
	if (num == 1)
		return;
	vector<int>tmp(N);
	int p = getPrime(num);
	int len = num / p;
	int k = index;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < p; j++)
			tmp[index + i + j * len] = answer[k++];

	for (int i = index; i < index + num; i++)
		answer[i] = tmp[i];

	for (int i = 0; i < p; i++)
		dividing(index + i * len, len);
}
vector<int> solution(int n) {
	N = n;
	for (int i = 1; i <= n; i++)
		answer.push_back(i);
	dividing(0, n);

	return answer;
}