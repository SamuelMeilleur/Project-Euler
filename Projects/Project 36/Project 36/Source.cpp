#include <iostream>
#include <bitset>
#define MAX 1000000

using namespace std;

int nbDigitsBase10(int number) {
	int counter(0);
	while (number) {
		number /= 10;
		++counter;
	}
	return counter;
}

int nbDigitsBase2(int number) {
	int counter = 0;
	while (number) {
		number /= 2;
		++counter;
	}
	return counter;
}

bool isPalindromeBase10(int number) {
	const int nbDigits = nbDigitsBase10(number);
	int* digits = new int[nbDigits];

	for (int i = 0; i < nbDigits; ++i) {
		digits[i] = (number % int(pow(10, i + 1))) / pow(10, i);
	}

	bool isPalindrome = true;
	for (int i = 0; i < nbDigits / 2; ++i) {
		if (digits[i] != digits[nbDigits - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	return isPalindrome;
}

bool isPalindromeBase2(int number) {
	const int nbDigits = nbDigitsBase2(number);
	int* digits = new int[nbDigits];

	for (int i = 0; i < nbDigits; ++i) {
		digits[i] = (number % int(pow(2, i + 1))) / pow(2, i);
	}

	bool isPalindrome = true;
	for (int i = 0; i < nbDigits / 2; ++i) {
		if (digits[i] != digits[nbDigits - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	return isPalindrome;
}

int main() {
	unsigned int sum = 0;
	for (unsigned int n = 1; n < MAX; n+=2) {
		if (isPalindromeBase10(n) && isPalindromeBase2(n)) {
			sum += n;
		}
	}
	cout << sum << endl;

}