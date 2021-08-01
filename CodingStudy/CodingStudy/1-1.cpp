#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> arr(2046, vector<bool>(4090, false));

void triangle(int x, int y, int size) { // 3 -> 5
	arr[x][y] = true;
	for (int i = 1; i <= size ; i++) {
		arr[x + i][y + i] = true;
		arr[x + i][y - i] = true;
	}
	x += (size + 1);
	y -= (size + 1);
	for (int i = 0; i < size * 2 + 3; i++)
		arr[x][y + i] = true;
}
void reTriangle(int x, int y, int size) { // 3 -> 5
	for (int i = 0; i <= size+1; i++) {
		arr[x][y + i] = true;
		arr[x][y - i] = true;
	}
	int y1 = y - (size + 1);
	for (int i = 1; i <= size; i++)
		arr[x + i][y1 + i] = true;
	y1 = y + (size + 1);
	for (int i = 1; i <= size+1; i++)
		arr[x + i][y1 - i] = true;
}

void triTree(int x, int y, int size, int k) {
	if (k % 2 == 1) {
		triangle(x, y, size);
		x += (size + 1) /2;
	}
	else {
		reTriangle(x, y, size);
		x++;
	}
	size -= 3;
	size /= 2;

	if (k == 0)
		return;
	triTree(x, y, size, k - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, size = 1, k = 0;
	cin >> N;
	for(int i = 2; i < N; i++){ // a[n] = 2 * a[n-1] + 3
		size *= 2;
		size += 3;
	}
	if (N == 1) {
		cout << "*";
		return 0;
	}
	triTree(0, size + 1, size, N);
	int len = size * 2 + 3;
	for (int i = 0; i < size + 2; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i][j])
				cout << "*";
			else
				cout << " ";
			if (N % 2 == 0) {
				if (j == len - i)
					break;
			}
			else
				if (j == len/2 +i)
					break;
				
		}
		if(i != size+1)
			cout << "\n";
	}
	return 0;
}