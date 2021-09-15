#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	double D, H, W;
	cin >> D >> H >> W;
	double ratio = pow(D, 2) / (pow(H, 2) + pow(W, 2));
	ratio = sqrt(ratio);
	cout << (int) (ratio * H) << " " << (int) (ratio * W);	
	return 0;
}