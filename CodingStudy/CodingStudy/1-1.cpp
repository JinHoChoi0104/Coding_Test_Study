#include <iostream>

using namespace std;


// BAEKJOON 1107
// 3 case
// 
// 1_1. dial number correct (if M != 10;  else if case 1_1;  else 1_2) 
// 1_2. dial number -> + or -
// 1_2_1 up dial, 1_2_2 down dial
// 2. + or - (must get)

int dial[10]; // 1: usable, 2: broken
int pow(int n, int digit)
{
	int num = 1;
	for (int i = 0; i < digit; i++) {
		num *= n;
	}
	return num;
}

int check_digits(int N) { //check how many digits
	int digit = 1;
	while (N > 9) {
		digit++;
		N /= 10;
	}
	return digit;
}

int check_dialdisable(int num, int digit) { //return where is dialdisalbe , -1 if diable
	int n = digit - 1 ;
	do {
		//cout << num/pow(10,n) << "  " << pow(10, n) << endl;
		if (dial[num / pow(10,n)] == 0) //check it from front
			return n;
		num %= pow(10,n);
		n--;
	} while (n > -1);
	return n;
}




int main() {
	for (int i = 0; i < 10; i++)
		dial[i] = 1;

	int N, M;
	cin >> N >> M;

	int broken_dial_num;
	for (int i = 0; i < M; i++) {
		cin >> broken_dial_num;
		dial[broken_dial_num] = 0;
	}
	int digit = check_digits(N);
	//cout << N << "   " << digit << endl;
	//cout << check_dialdisable(N, digit) <<endl;
	int cnt = 0, num = N, n = 0; //check whether case 1_1
	int dial1 = 500000; // case 1
	if (M != 10) {
		// get dialog
		for (int i = 0; i < digit; i++) {
			if (dial[num % 10] == 1)
				cnt++;
			num /= 10;
		}
		if (cnt == digit) // case 1_1
			dial1 = digit;

		else { // case 1_2
			// case 1_2_1
			num = N;
			n = check_dialdisable(num, digit);
			while (n > -1) {

				num /= pow(10, n);
				num *= pow(10, n);
				num += pow(10, n);
				n = check_dialdisable(num, digit);
				//cout << num << " n: "<<n << endl;
			}
			int up;
			//cout << num << " n: " << n << endl;
			up = num - N + check_digits(num); // (+)dial + number dial
			//cout << "up: " << up << endl;
			// case 1_2_2
			num = N;
			while (check_dialdisable(num, digit) > -1) {
				if (num < 0)
					break;
				num--;
			}
			int down;
			//cout << "num: " << num << endl;
			if (num < 0)
				down = 10000000;
			else
				down = N - num + check_digits(num); // (-)dial + number dial
			// cout << "down: " << down << endl;



			up > down ? dial1 = down : dial1 = up;

		}
	}

	int dial2 = 0; // case 2
	(N - 100) >= 0 ? dial2 = N - 100 : dial2 = 100 - N;



	// comparing case1 and case2
	if (dial1 > dial2)
		cout << dial2;
	else
		cout << dial1;
	return 0;
}