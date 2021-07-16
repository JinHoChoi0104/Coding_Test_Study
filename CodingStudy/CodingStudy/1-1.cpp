#include<iostream>
#include<vector>
using namespace std;
struct doc { int rank, value; };

void clearImportance(int *importance){
	for (int i = 0; i < 10; i++)
		importance[i] = 0;
}

int main(void) {
	vector <doc> arr;
	int importance[10] = { 0 };
	int T = 1, N = 0, M = 0, input = 0, target = 0, cnt, index, value_index; // M =  target, target = target's value
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		clearImportance(importance);//reset importance []

		for (int j = 0; j < N; j++) {
			scanf("%d", &input);
			arr.push_back({ j, input });
			importance[input]++;
			if (j == M)
				target = input;
		}

		index = 0, value_index = 9, cnt = 0;
		while (value_index > target) { //remove higer importance
			while (importance[value_index] > 0) {
				if (arr[index].value == value_index) {
					cnt++;
					importance[value_index]--;
				}
				index++;
				if (index == N)
					index = 0;
			}
			value_index--;
		}
		
		while (1) { // now value index = target
			if (arr[index].value == target) {
				cnt++;
				if (arr[index].rank == M)
					break;
			}
			index++;
			if (index == N)
				index = 0;
		}
		cout << cnt << endl;
		arr.clear();
	}

	return 0;
}