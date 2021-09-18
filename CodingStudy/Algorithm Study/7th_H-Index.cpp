#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int i, n = citations.size();
	sort(citations.begin(), citations.end()); //우선 정렬 한다
	for (i = 0; i <= citations[n - 1]; i++) { //최대 가능 인용수는 제일 많이 인용된 논문의 수이다
		int index = lower_bound(citations.begin(), citations.end(), i) - citations.begin();
		//index는 i이상 수들 중 첫 번째 수의 인덱스이다
		//앞에 수들, 즉 나머지 논문들은 i번 미만으로 인용됬으므로, h번 이하 인용을 만족
		if (n - index >= i) // n - index 는 i번 이상 인용된 논문의 수
			continue; // i번 이상 인용된 논문의 수가 i 개 이상이면 패스
		break; //아니면 브레이크
	}
	return i - 1; //아닐 때 나왔으니까 -1 해주고 리턴
}