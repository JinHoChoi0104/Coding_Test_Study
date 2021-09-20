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

	int findB(int n) { //가장 밑 반환
		if (n == bottom[n]) return n;
		return findB(bottom[n]);
	}
	int findT(int n) { //가장 위 반환
		if (n == top[n]) return n;
		return findT(top[n]);
	}
	int getSize(int n) {
		if (n == bottom[n]) return 1;
		return getSize(bottom[n]) + 1;
	}
	
	int reverse(int n) {//뒤집어진 후 기둥의 가장 밑 원소 반환
		int ans = findT(n);
		if (n == top[n]) //1개면 뒤집을 것도 없다
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
		if (isOnly) { //밑에 뭐가 없다
			int next=n;
			while (!s2.empty()) { //밑에 뭐가 없으면 탑과 바텀 그대로 바꾸면 된다.
				n = next;
				next = bottom[n];
				top[n] = s2.top(), bottom[n] = s1.top();
				s2.pop(), s1.pop();
			}
		}
		else{//밑에 뭐가 있으면 위에는 무조건 2개
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

//색을 저장, 가장 위에 있는 말 번호 저장
pieces p(10);
int movePiece(int x, int y, int num) {
	int& ret2 = board[p.pos[p.findB(num)].first][p.pos[p.findB(num)].second];
	if (p.bottom[num] != num) {
		p.top[p.bottom[num]] = p.bottom[num];
		ret2 = p.bottom[num];
	}
	//이동하기 전에 원래 있던 곳 말의 위를 비어준다
	else
		ret2 = -1;


	int& ret = board[x][y];
	if (ret == -1) {//이동하는 곳에 아무것도 없어
		p.pos[num] = { x,y };//말에 좌표 저장
		p.bottom[num] = num; //가장 밑은 이제 num
	}
	else {//뭐가 있다
		p.bottom[num] = ret; //num 밑에 원래 있던 말의 top 저장
		p.top[ret] = num; //원래 있던거 위에 새로 온 말 탑승
	}
	ret = p.findT(num); //보드에 온 말 저장

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
			board[i][j] = -1;//보드 초기화
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
			//현재 위치
			int x = p.pos[p.findB(i)].first;
			int y = p.pos[p.findB(i)].second;
			dir = p.dir[i];
			
			int tox = x + m[0][dir], toy = y + m[1][dir];
			if (tox < 0 || tox >= N || toy < 0 || toy >= N) {//벗어나면 반대방향
				if (dir == 0 || dir == 2)
					dir++;
				else
					dir--;
				p.dir[i] = dir;
				tox = x + m[0][dir], toy = y + m[1][dir];
			}

			int size = 1;
			if (color[tox][toy] == 0) //흰색
				size = movePiece(tox, toy, i);
			else if (color[tox][toy] == 1) //빨간색
				size = movePiece(tox, toy, p.reverse(i));
			else { //파란색
				if (dir == 0 || dir == 2) //방향 반대로
					dir++;
				else
					dir--;
				p.dir[i] = dir;
				tox = x + m[0][dir], toy = y + m[1][dir];
				if (tox > -1 && tox < N && toy > -1 && toy < N) {
					if (color[tox][toy] == 0) //반대에 흰색
						size = movePiece(tox, toy, i);
					else if(color[tox][toy] == 1) //반대에 빨간색
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