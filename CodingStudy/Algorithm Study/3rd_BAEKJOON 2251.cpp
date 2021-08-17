#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int full[3]; //������ �뷮
vector < vector <bool>> visited(201, vector <bool>(201)); //a�� b�� ���¸� ���� ��¥�� ������ ����
struct water { int bottle[3]; };
queue <water> q;
set <int> s;//������ �뷮 ����, �ߺ� ��� X, �������� ����
/*
������ ���� �̵�
a ���� b ,c
b ���� a, c
c ���� a, b
*/
void pour() { 
	int b[3], b1[3], dis;
	while (!q.empty()) {
		for (int i = 0; i < 3; i++)
			b[i] = q.front().bottle[i];
		q.pop();
		for (int i = 0; i < 3; i++) { //i����
			for (int j = 0; j < 3; j++) { //j��
				if (i == j || b[j] == full[j]) //���� ������ �̵��� �ǹ̰� ���� Ȥ�� j�� �� á�ų�
					continue;
				for (int k = 0; k < 3; k++)
					b1[k] = b[k];
				dis = full[j] - b[j]; //j�� �� �� �ִ� ���� ��
				if (dis >= b[i]) { //i�� ������ ����
					b1[j] = b[j] + b[i];
					b1[i] = 0;
				}
				else { //���� ����
					b1[j] += dis;
					b1[i] -= dis;
				}
				if (!visited[b1[0]][b1[1]]) { //�� ���� �������� ���� ���̽��� Ǫ��
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