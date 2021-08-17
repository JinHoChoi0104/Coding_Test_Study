#include<iostream>
#include<set>

using namespace std;

int main(void) {
	multiset<int> A; //�������� ����
	multiset<int, greater<>> B; //�������� ����
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
	//���� ū ���� ���� �������� ���ʷ� �����ش�
	for (set<int>::iterator it1 = A.begin(),it2 = B.begin(); it1 != A.end(); it1++, it2++) 
		sum += (*it1) * (*it2);

	printf("%d", sum);
	return 0;
}