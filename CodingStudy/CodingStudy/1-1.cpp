#include <iostream>
int low = 100000;

int HideAndSick(int pos, int K, int depth) { // pos: position where SooBin is placed now
	if (depth <= low - 1) {
		if (K == pos)
			low = depth;
		else if (K < pos)
			depth += pos - K;
		else {
			if (K == pos * 2) {
				depth = HideAndSick(pos * 2, K, depth + 1);;
			}
			else {
				int a = HideAndSick(pos * 2, K, depth + 1);
				int b = HideAndSick(pos + 1, K, depth + 1);
				int c = HideAndSick(pos - 1, K, depth + 1);
				int min = a > b ? b : a;
				min = min > c ? c : min;
				depth = min;
			}
		}
	}
	return depth;
}


int main()
{
	int N, K; 
	scanf("%d %d", &N, &K); 

	printf("%d", HideAndSick(N, K, 0));

}