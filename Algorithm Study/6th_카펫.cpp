#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int h, w;
	for (int i = yellow; i > 0; i--) { //가로 길이 yellow에서 1까지
		if (yellow % i == 0) {
			w = i, h = yellow / i; //가로, 세로
			if (2 * (w + h) + 4 == brown)
				break;
		}
	}
	answer.push_back(w + 2);
	answer.push_back(h + 2);
	return answer;
}