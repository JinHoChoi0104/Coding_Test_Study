#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
void getEnergy(vector<int>arr, int index, int power) { //조합을 만든다
	power += arr[index - 1] * arr[index + 1]; //앞뒤 곱을 에너지에 더해준다
	arr.erase(arr.begin()+index); //그리고 중간은 삭제
	if (arr.size() == 2) { //2개 남으면 스탑
		ans = max(ans, power);
		return;
	}
	for (int i = 1; i < arr.size() - 1; i++) //제일 앞고 뒤는 제외하고 선택한다.
		getEnergy(arr, i, power);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num;
	vector<int>arr;
	for (cin >> n; n-- > 0;) {
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 1; i < arr.size() - 1; i++)
		getEnergy(arr, i, 0); //재귀를 이용해 조합 구현
	cout << ans;
	return 0;
}