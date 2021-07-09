// BAEKJOON 2156
#include<iostream>

using namespace std;

int main(void) {
	int N; 
	scanf("%d", &N);

	int arr[10000];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int drinkingState[4] = { 0 }; // OX, XO, OO, XX , 4 states of sipping
	int OX = 0, XO = 0, OO = 0, XX = 0;

	for (int i = 0; i < N; i++) {
		OX = drinkingState[0];
		XO = drinkingState[1];
		OO = drinkingState[2];
		XX = drinkingState[3];
		
		//XO , OO -> OX
		drinkingState[0] = XO > OO ? XO : OO;
		//OX , XX -> XO
		drinkingState[1] = OX > XX ? OX + arr[i] : XX + arr[i];
		//XO -> OO
		drinkingState[2] = XO + arr[i];
		//OX -> XX
		drinkingState[3] = OX;
	}

	int max_sip = 0;
	for (int i = 0; i < 4; i++) 
		max_sip < drinkingState[i] ? max_sip = drinkingState[i] : NULL;
	
	cout << max_sip;
	return 0;
}