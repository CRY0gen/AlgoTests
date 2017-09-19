/*
	ALGORITHM ID 01
	AUTH: CRY0g3n
	USAGE: Check if numbers are in the same position in arrays, and check who are not
	VERSION: 1.0.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//Just creates the randnums and the testrandnums
	int randnums[4];
	int test[4];
	int ulocks[4], rlocks[4] , uwlocks[4];
	int rightPos = 0;
	int wrongPos = 0;
	srand(time(NULL));
	for (int x = 0; x < 4; x = x + 1){
		randnums[x] = rand() % 10;
		test[x] = rand() % 10;
		ulocks[x] = -1;
		rlocks[x] = -1;
		uwlocks[x] = -1;
	}
	for (int i = 0; i < 4; i = i + 1){
		printf("Rand Num: %d Rand User: %d\n", randnums[i], test[i]);
	}
	printf(".");
	for (int i = 0; i < 4; i = i + 1){
		if (randnums[i] == test[i]){
			//printf("Num: %d Pos: %d\n", test[i], i);
			ulocks[i] = test[i];
			rlocks[i] = randnums[i];
			rightPos = rightPos + 1;
		}
	}
	printf(".");
	printf(".");
	for (int i = 0; i < 4; i = i + 1){
		printf(".");
		for (int x = 0; x < 4; x = x + 1){
			if(randnums[x] == test[i] && test[i] != ulocks[i]  && i != x && randnums[x] != rlocks[x] && test[i] != uwlocks[i]){
				//printf("Num: %d Pos: %d\n", test[i], i);
				rlocks[x] = randnums[x];
				uwlocks[i] = test[i];
				//printf("Adding to lock: %d\n", randnums[x]);
				wrongPos = wrongPos + 1;
			}
		}
		printf(".");
	}
	printf("\n END \n");
	printf("Numeri nella posizione giusta: %d\n", rightPos);
	printf("Numeri nella posizione sbagliata: %d\n", wrongPos);
}
