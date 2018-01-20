#include <iostream>
#include <cmath>
#define MAX 11

using namespace std;

bool isPrime(unsigned int number) {
	if (number == 1)
		return false;
	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0)
			return false;
	}
	return true;
}

unsigned int nDigits(unsigned int number) {
	unsigned int digits = 0;
	while (number) {
		++digits;
		number /= 10;
	}
	return digits;
}

bool truncatableFromRight(unsigned int number) {
	while (number) {
		number /= 10;
		if (!isPrime(number))
			return false;
	}
	return true;
}

bool truncatableFromLeft(unsigned int number) {
	unsigned int digits = nDigits(number);
	while (number) {
		unsigned int power = pow(10, --digits);
		unsigned int value = number / power;
		number -= value * power;
		if (!isPrime(number))
			return false;
	}
	return true;
	
}



int main() {
	unsigned int count = 0;
	unsigned int sum = 0;
	unsigned int n = 10;
	while (count != MAX) {
		if (isPrime(n) && truncatableFromRight(n) && truncatableFromLeft(n)) {
			sum += n;
			++count;
		}
		++n;
	}
	
	
	cout << sum << endl;

	return 0;
}