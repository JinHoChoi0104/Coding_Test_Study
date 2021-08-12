#include <iostream>
#include <memory.h>
using namespace std;

int main() {
	int floor, pos, to, u, d, cnt = 0, rate;
	bool isStair = false, visited[1000001];
	memset(visited, false, 1000001);
	scanf("%d %d %d %d %d", &floor, &pos, &to, &u, &d);

	while (to != pos) {
		if (visited[pos]) {
			isStair = true;
			break;
		}
		visited[pos] = true;
		if (pos < to) { // under target
			if (u == 0) { //but can't go up
				isStair = true;
				break;
			}
			rate = (to - pos) / u;
			if (rate > 0) { //go up much as you can
				cnt += rate;
				pos += rate * u;
			}
			else { // if you go up, and you pass the target
				cnt++;
				pos -= d; // then go downward
				if (pos < 1) {  //if you can't go down
					pos += d;
					pos += u; //then just go upward
					if (pos > floor) { //and if you can't go up then use stairs!
						isStair = true;
						break;
					}
				}
			}
		}
		else { //to < pos
			if (d == 0) {
				isStair = true;
				break;
			}
			rate = (pos - to) / d;
			if (rate > 0) {
				cnt += rate;
				pos -= d * rate;
			}
			else {
				cnt++;
				pos += u;
				if (pos > floor) {
					pos -= u;
					pos -= d;
					if (pos < 1) {
						isStair = true;
						break;
					}
				}
			}
		}
	}
	if (isStair)
		printf("use the stairs");
	else
		printf("%d", cnt);
	return 0;
}