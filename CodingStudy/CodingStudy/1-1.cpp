#include <iostream>

using namespace std;


// BAEKJOON 1107
// 3 case
// 
// 1_1. dial number correct (if M != 10;  else if case 1_1;  else 1_2) 
// 1_2. dial number -> + or -
// 1_2_1 up dial, 1_2_2 down dial
// 2. + or - (must get)

int dial[10]; // 1: usable, 0: broken
int max_dialog, min_dialog, min_dialog2, max_num = 0;

int check_digits(int N) { //check how many digits
	int digit = 1;
	while (N > 9) {
		digit++;
		N /= 10;
	}
	return digit;
}



int pow(int n, int digit)
{
	int num = 1;
	for (int i = 0; i < digit; i++) 
		num *= n;
	
	return num;
}

int up_dial(int num, int digit) { // ... 3 2 1 0
	int n = num % pow(10, digit+1);
	n /= pow(10, digit); // a= 2

	if (dial[n] == 1) { // diable
		if (digit != 0)
			num = up_dial(num, digit - 1);
	}
	else if (n == 9 || n == max_dialog) { //disdialbe and has to round up
		num /= pow(10, digit + 1);
		num *= pow(10, digit + 1);
		num += pow(10, digit + 1);
		num = up_dial(num, digit + 1);
	}
	else { //disdialbe and doesn't has to round up		
		for (int j = n + 1; j < 10; j++) { 	
			if (dial[j] == 1) {		
				num /= pow(10, digit + 1);
				num *= pow(10, digit + 1);
				num += j * pow(10, digit);
				for (int k = digit - 1; k > -1; k--)
					num += min_dialog * pow(10, k);
				break;
			}
		}
	}

	return num;
}

int down_dial(int num, int digit) { // ... 3 2 1 0
	//cout << "num: " << num << "  digit: " << digit << endl;
	//int n = num % pow(10, digit + 1);
	if (num >= pow(10, digit) && num != 0) { //num > 9
		int n = num % pow(10, digit + 1);
		n /= pow(10, digit); // a= 2
		//cout << "num: " << num << "  digit: " << digit << endl;
		if (dial[n] == 1) { // diable
			if (digit != 0)
				num = down_dial(num, digit - 1);
		}
		else {//if (n == 0 || n == min_dialog || min_dialog2) { //disdialbe
			num /= pow(10, digit);
			num *= pow(10, digit);
			num -= 1;
			num = down_dial(num, digit);
		}
		/*
			else { //disdialbe and doesn't has to round up
				for (int j = n - 1; j > -1; j--) {
					if (dial[j] == 1) {
						num /= pow(10, digit + 1);
						num *= pow(10, digit + 1);
						num += j * pow(10, digit);
						for (int k = digit - 1; k > -1; k--)
							num += max_dialog * pow(10, k);
						break;
					}
				}
			}*/
	}
	else if (num == 0);
		//num = -1;
	else
		num = down_dial(num, digit - 1);

	//cout << "return num: " << num << "  digit: " << digit << endl;
	return num;
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

	 //check whether case 1_1
	int dial1 = 500000; // case 1
	if (M != 10) {
		
		for (int i = 0; i < 10; i++) 
			if (dial[i] == 1)
				max_dialog = i;
		for (int i = 9; i > -1; i--)
			if (dial[i] == 1)
				min_dialog = i;

		int digit = check_digits(N);
		for (int i = 0; i < digit; i++) 
			max_num += max_dialog * pow(10, i);


		int cnt = 0, num = N, num2 = N;;
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
			num = up_dial(N, digit - 1);
			
			int up;
			
			if (N < num)
				up = num - N + check_digits(num); // (+)dial + number dial
			else
				up = 1000000;
			//cout << "up: " << up << endl;

			// case 1_2_2
			num = N;
			num = down_dial(N, digit - 1);
			//cout << num << endl;
			int down;
			if (num == N)
				down = 10000000;
			else
				down = N - num + check_digits(num); // (-)dial + number dial
		//	cout << "down: " << down << endl;

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