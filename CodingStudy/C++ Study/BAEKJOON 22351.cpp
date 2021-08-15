#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int len;
vector<int> a;

void findFront() {
	int a1 = 0, a2 = 0;
	for (int i = 0; i < 3; i++)
		a1 += a[i] * pow(10, 3 - 1 - i);
	for (int i = 0; i < 3; i++)
		a2 += a[i + 3] * pow(10, 3 - 1 - i);

	if (a1 + 1 == a2) // 3 3
		cout << a1 << " ";
	else if (a[0] == 9 && a[1] == 9) //2 3
		cout << "99 ";
	else {
		a1 = 0, a2 = 0;
		for (int i = 0; i < 2; i++)
			a1 += a[i] * pow(10, 1 - i);
		for (int i = 0; i < 2; i++)
			a2 += a[i + 2] * pow(10, 1 - i);
		if (a1 + 1 == a2)  // 2 2
			cout << a1 << " ";
		else if (a[0] == 9 && a[1] == 1)  // 1 2
			cout << a[0] << " ";
		else  //1 1 
			cout << a[0] << " ";
	}
}
void findBack() {
	int	a1 = 0, a2 = 0;
	for (int i = 0; i < 3; i++)
		a1 += a[len - 6 + i] * pow(10, 2 - i);
	for (int i = 0; i < 3; i++)
		a2 += a[len - 3 + i] * pow(10, 2 - i);
	if (a1 + 1 == a2) // end: 3 3
		cout << a2;
	else if (a2 == 100)
		cout << 100;
	else {
		a1 = 0, a2 = 0;
		for (int i = 0; i < 2; i++)
			a1 += a[len - 4 + i] * pow(10, 1 - i);
		for (int i = 0; i < 2; i++)
			a2 += a[len - 2 + i] * pow(10, 1 - i);
		if (a1 + 1 == a2)
			cout << a2; // end 2
		else if (a2 == 10)
			cout << 10;
		else
			cout << a[len - 1];
	}

}
int main() {
	string str;
	cin >> str;
	int num;
	len = str.length();
	for (int i = 0; i < len; i++) {
		num = str.at(i) - 48; //1 = 49
		a.push_back(num);
	}

	if (len == 1)
		cout << a[0] << " " << a[0];
	else if (len == 2) {
		if (a[0] + 1 == a[1])
			cout << a[0] << " " << a[1];
		else
			cout << str << " " << str;
	}
	else if (len == 3 || len == 4)
		if (a[0] + 1 == a[1] && a[1] + 1 == a[2])  // 1 1 1 1
			cout << a[0] << " " << a[len - 1];
		else if (a[len - 3] == 9 && a[len - 2] == 1 && a[len - 1] == 0)  // 1 2 or 1 1 2
			cout << a[0] << " 10";
		else if (len == 3)
			cout << str << " " << str;
		else
			cout << a[0] << a[1] << " " << a[2] << a[3];
	else if (len == 5) {  // 1 1 1 1 1, 1 1 1 2, 1 2 2, 2 3
		if (a[0] + 1 == a[1] && a[1] + 1 == a[2]) {
			if (a[2] + 1 == a[3])  // 1 1 1 1 1
				cout << a[0] << " " << a[4];
			else  // 1 1 1 2
				cout << "7 10";
		}
		else
			if (a[1] != 9) // 1 2 2
				cout << "9 11";
			else // 2 3
				cout << "99 100";
	}
	else { // len >= 6
		findFront();
		findBack();
	}

	return 0;
}