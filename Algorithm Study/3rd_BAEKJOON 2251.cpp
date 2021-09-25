#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int full[3]; //물통의 용량
vector < vector <bool>> visited(201, vector <bool>(201)); //a와 b의 상태만 저장 어짜피 총합은 같다
struct water { int bottle[3]; };
queue <water> q;
set <int> s;//가능한 용량 저장, 중복 허용 X, 오름차순 정렬
/*
가능한 물의 이동
a 에서 b ,c
b 에서 a, c
c 에서 a, b
*/
void pour() { 
	int b[3], b1[3], dis;
	while (!q.empty()) {
		for (int i = 0; i < 3; i++)
			b[i] = q.front().bottle[i];
		q.pop();
		for (int i = 0; i < 3; i++) { //i에서
			for (int j = 0; j < 3; j++) { //j로
				if (i == j || b[j] == full[j]) //같은 물병은 이동의 의미가 없다 혹은 j가 꽉 찼거나
					continue;
				for (int k = 0; k < 3; k++)
					b1[k] = b[k];
				dis = full[j] - b[j]; //j에 들어갈 수 있는 물의 양
				if (dis >= b[i]) { //i의 물양이 적다
					b1[j] = b[j] + b[i];
					b1[i] = 0;
				}
				else { //양이 많다
					b1[j] += dis;
					b1[i] -= dis;
				}
				if (!visited[b1[0]][b1[1]]) { //한 번도 나온적이 없는 케이스면 푸시
					q.push({ b1[0],b1[1],b1[2] });
					visited[b1[0]][b1[1]] = true;
					if(b1[0]==0)
						s.insert(b1[2]);
				}
			}
		}
	}
}
int main(void) {
	scanf("%d %d %d", &full[0], &full[1], &full[2]);

	q.push({0,0,full[2]});
	s.insert(full[2]);
	visited[0][0] = true;

	pour();
	for (auto it = s.begin(); it != s.end(); it++)
		printf("%d ", *it);

	return 0;
}