#include <iostream>
#include <vector>
using namespace std;
int total_cost = 0;
int a[500];
void file_division(int l, int r, int cost) {
	//cout << l << r << endl;
	if (l == r)
		return;
	int lsum = 0, rsum = 0, index;
	int i = l, j = r;
	while (i <= j) {
		if (lsum < rsum) {
		//	index = i;
			lsum += a[i++];
		}
		else {
			//index = j;
			rsum += a[j--];
		}
	}
	i--;
	j++;
	

	cout << lsum << " "<<rsum << endl;
	if (l != i)
		total_cost += lsum;
	if (j != r)
		total_cost += rsum;
	if(l+1 !=i)
		file_division(l, i, lsum);
	if(j+1!=r)
		file_division(j, r, rsum);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	int T, K, cost_sum;
	scanf("%d", &T);
	
	
	while (T--) {
		scanf("%d", & K);
		cost_sum = 0;
		for (int i = 0; i < K; i++) {
			scanf("%d", &a[i]);
			cost_sum += a[i];
		}
		total_cost = cost_sum;
		file_division(0, K - 1, cost_sum);
		printf("%d\n", total_cost);
	}
	return 0;
}