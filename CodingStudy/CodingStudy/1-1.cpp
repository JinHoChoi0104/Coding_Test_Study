#include<iostream>
#include<set>

using namespace std;

int main(void) {
	multiset<int> A; //오름차순 정렬
	multiset<int, greater<>> B; //내림차순 정렬
	int N, num, sum = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		A.insert(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		B.insert(num);
	}
	//제일 큰 수와 제일 작은수를 차례로 곱해준다
	for (set<int>::iterator it1 = A.begin(),it2 = B.begin(); it1 != A.end(); it1++, it2++) 
		sum += (*it1) * (*it2);

	printf("%d", sum);
	return 0;
}