#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int color[12][12], board[12][12];

struct pieces {
	vector<int> bottom, top, dir; 
	vector<pair<int, int>>pos; //x, y

	pieces(int n) :bottom(n), top(n), dir(n), pos(n) {
		for (int i = 0; i < n; i++)
			bottom[i] = i, top[i] = i;
	}

	int findB(int n) { //���� �� ��ȯ
		if (n == bottom[n]) return n;
		return findB(bottom[n]);
	}
	int findT(int n) { //���� �� ��ȯ
		if (n == top[n]) return n;
		return findT(top[n]);
	}
	int getSize(int n) {
		if (n == bottom[n]) return 1;
		return getSize(bottom[n]) + 1;
	}
	
	int reverse(int n) {//�������� �� ����� ���� �� ���� ��ȯ
		int ans = findT(n);
		if (n == top[n]) //1���� ������ �͵� ����
			return n;
		int x = pos[findB(n)].first, y = pos[findB(n)].second;
		board[x][y] = n;
		pos[ans].first = x, pos[ans].second = y;
		stack<int>s1, s2;
		bool isOnly = n == bottom[n] ? true : false;

		while (1) {
			s1.push(top[n]), s2.push(bottom[n]);
			if (n == top[n])
				break;
			n = top[n];
		}
		if (isOnly) { //�ؿ� ���� ����
			int next=n;
			while (!s2.empty()) { //�ؿ� ���� ������ ž�� ���� �״�� �ٲٸ� �ȴ�.
				n = next;
				next = bottom[n];
				top[n] = s2.top(), bottom[n] = s1.top();
				s2.pop(), s1.pop();
			}
		}
		else{//�ؿ� ���� ������ ������ ������ 2��
			int under = bottom[n];
			int under2 = bottom[under]; //0
			top[under2] = n;
			top[under] = under;
			bottom[under] = n;
			top[n] = under;
			bottom[n] = under2;
		}
		return ans;
	}
};

//���� ����, ���� ���� �ִ� �� ��ȣ ����
pieces p(10);
int movePiece(int x, int y, int num) {
	int& ret2 = board[p.pos[p.findB(num)].first][p.pos[p.findB(num)].second];
	if (p.bottom[num] != num) {
		p.top[p.bottom[num]] = p.bottom[num];
		ret2 = p.bottom[num];
	}
	//�̵��ϱ� ���� ���� �ִ� �� ���� ���� ����ش�
	else
		ret2 = -1;


	int& ret = board[x][y];
	if (ret == -1) {//�̵��ϴ� ���� �ƹ��͵� ����
		p.pos[num] = { x,y };//���� ��ǥ ����
		p.bottom[num] = num; //���� ���� ���� num
	}
	else {//���� �ִ�
		p.bottom[num] = ret; //num �ؿ� ���� �ִ� ���� top ����
		p.top[ret] = num; //���� �ִ��� ���� ���� �� �� ž��
	}
	ret = p.findT(num); //���忡 �� �� ����

	return p.getSize(ret);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N, K, x, y, dir;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> color[i][j];
			board[i][j] = -1;//���� �ʱ�ȭ
		}
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> dir;
		p.pos[i] = { --x, --y };
		p.dir[i] = dir - 1;
		board[x][y] = i;
	}

	int m[2][4] = { {0,0,-1,1},{1,-1,0,0} };
	
	for (int t = 1; t <= 1000; t++) {
		for (int i = 0; i < K; i++) {
			//���� ��ġ
			int x = p.pos[p.findB(i)].first;
			int y = p.pos[p.findB(i)].second;
			dir = p.dir[i];
			
			int tox = x + m[0][dir], toy = y + m[1][dir];
			if (tox < 0 || tox >= N || toy < 0 || toy >= N) {//����� �ݴ����
				if (dir == 0 || dir == 2)
					dir++;
				else
					dir--;
				p.dir[i] = dir;
				tox = x + m[0][dir], toy = y + m[1][dir];
			}

			int size = 1;
			if (color[tox][toy] == 0) //���
				size = movePiece(tox, toy, i);
			else if (color[tox][toy] == 1) //������
				size = movePiece(tox, toy, p.reverse(i));
			else { //�Ķ���
				if (dir == 0 || dir == 2) //���� �ݴ��
					dir++;
				else
					dir--;
				p.dir[i] = dir;
				tox = x + m[0][dir], toy = y + m[1][dir];
				if (tox > -1 && tox < N && toy > -1 && toy < N) {
					if (color[tox][toy] == 0) //�ݴ뿡 ���
						size = movePiece(tox, toy, i);
					else if(color[tox][toy] == 1) //�ݴ뿡 ������
						size = movePiece(tox, toy, p.reverse(i));
				}
			}

			if (size >= 4) {
				cout << t;
				return 0;
			}
		}
	}
	cout << "-1";
	return 0;
}