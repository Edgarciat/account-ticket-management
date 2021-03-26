/*
	==================================================
		Assignment #2  Milestone #2
	==================================================
	Name   : Edgar David Garcia Torres
	ID     : 104433206
	Email  : edgarcia-torres@myseneca.ca
	Section: ZZA
*/
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>

int currentYear(void) {
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

void clearStandardInputBuffer(void) {
	while (getchar() != '\n')
	{
		; // On purpose: do nothing 
	}
}

int getInteger() {

	char NewLine = 'x';
	int ValidInt;
	do {
		scanf("%d%c", &ValidInt, &NewLine);
		
		if (NewLine != '\n') {
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} while (NewLine != '\n');
	return ValidInt;
}

int getPositiveInteger() {
	int value;
	do {
		value = getInteger();
		if (value < 0) {
		//	printf("ERROR: Value must be a positive integer greater than zero: ");
			printf("ERROR: Value must be positive or zero: ");
		}
	//} while (value<=0);
	} while (value < 0);
	return value;
}

int getIntFromRange(int min, int max) {
	int positiveInt = 0;
	do {
		positiveInt = getInteger();
		if (positiveInt < min || positiveInt > max) {
			//clearStandardInputBuffer();
			printf("ERROR: Value must be between %d and %d inclusive: ",min,max);
		}
	} while (positiveInt <min || positiveInt > max);
	return positiveInt;
}

double getDouble() {
	char newline = 'x';
	double Doble;
	do {
		scanf("%lf%c", &Doble, &newline);
		
		if (newline != '\n') {
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (newline != '\n');
	return Doble;
}

double getPositiveDouble() {
	double Doble = 0.0;
	do {
		Doble = getDouble();
		if (Doble <= 0) {
			//clearStandardInputBuffer();
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	} while (Doble <= 0);
	return Doble;
	
}

char getCharOption(char C[]) {
	char L[30] = { 0 };
	int e;
	for (e = 0; e < 30; e++) {
		L[e] = C[e];
	}
	int limit = 0, seen = 0;
	for (e = 1; e < 31; e++) {
		if (L[e - 1] == 0 && seen == 0) {
			limit = e;
			if (limit != 0) {
				seen = 1;
			}
		}
	}
	limit = limit - 1;
	int i, found = 0;
	char newline = 'x';
	int v = 0, c = 0;
	char V[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	do {
		scanf("%[^\n]s%c", V, &newline);
		clearStandardInputBuffer();
		if (V[1] == '\0') {
			found = 0;

			if (V[0] == 'a' && C[0] == 'A') {
				found = 0;
			}
			else {
				for (i = 0; i < limit; i++) {
					v = V[0];
					c = L[i];
					if (v == c) {
						found = 1;
						goto R;
					}
				}
			}
			if (found == 0) {
				printf("ERROR: Character must be one of [%s]: ", C);
			}
		}
		else {
			printf("ERROR: Character must be one of [%s]: ", C);
		}
	} while (found == 0);
R:
	return C[i];
}


void getCString(char* C, int  min, int max) {
	char newline = 'x';
	int charcount = 0;
	int i;
	int valid = 1;
	do {
		valid = 1;
		char V[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		scanf("%[^\n]s%c", V, &newline);
		clearStandardInputBuffer();
		for (i = 0; i < 30; i++) {
			if (V[i] != '\0') {
				charcount = charcount + 1;
			}
		}
		for (i = 0; i < 30; i++) {
			C[i] = V[i];
		}
		if (min == max && charcount != min) {
			printf("ERROR: String length must be exactly %d chars: ", min);
			charcount = 0;
			valid = 0;
		}
		else {
			if (min != max && charcount < min) {
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
				charcount = 0;
				valid = 0;
			}
			else {
				if (charcount > max) {
					printf("ERROR: String length must be no more than %d chars: ", max);
					valid = 0;
					charcount = 0;
				}
			}
		}
		charcount = 0;
	} while (valid == 0);
}

