#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N;
	cin >> N;
	//나이 별로 벌레 저장
	vector<int> odd = {0, 1, 0, 0, 0}; //홀수 년도에 태어난 벌레들 
	vector<int> even(5,0); //짝수 년도에 태어남
	for (int i = 2; i <= N; i++) { //2년 째 부터 시작
		int sum = even[4];
		even[4] = even[3]; //짝수년도에 탄생한 개체는 1년 더 산다
		for (int k = 3; k > 0; k--) { 
			sum += (odd[k] + even[k]); //총 존재하는 개채 구한다
			odd[k] = odd[k - 1], even[k] = even[k - 1];  //한 살씩 나이든다, 사망하는 개체는 여기서 사라짐
		}
		

		if (i % 2 == 0)  //짝수년도에 탄생
			even[1] = sum;
		else //훌수년도에 탄생
			odd[1] = sum;
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		ans += (odd[i] + even[i]);
	cout << ans;
	return 0;
}