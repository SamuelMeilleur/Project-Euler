#include "Functions.h"
#include <cmath>
#include <iostream>

bool isEven(int number) {
	return !(number % 2);
}

int numberOfDigits(int number) {
	int counter = 0;
	while (number) {
		number /= 10;
		++counter;
	}
	return counter;
}

bool isPalindrome(int number) {
	const int nbDigits = numberOfDigits(number);
	int* digits = new int[nbDigits];

	for (int i = 0; i < nbDigits; ++i) {
		digits[i] = (number % int(pow(10, i+1)))/pow(10,i);
	}

	bool isPalindrome = true;
	for (int i = 0; i < nbDigits/2; ++i) {
		if (digits[i] != digits[nbDigits - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	

	return isPalindrome;
}