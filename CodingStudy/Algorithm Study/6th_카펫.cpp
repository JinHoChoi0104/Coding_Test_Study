#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int h, w;
	for (int i = yellow; i > 0; i--) { //���� ���� yellow���� 1����
		if (yellow % i == 0) {
			w = i, h = yellow / i; //����, ����
			if (2 * (w + h) + 4 == brown)
				break;
		}
	}
	answer.push_back(w + 2);
	answer.push_back(h + 2);
	return answer;
}