#include <iostream>
#include <cmath>
#define MAX 10000

int properDivisorSum(int number) {
	int sum = 1;

	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0) 
			sum += i + number / i;
	}
	return sum;
}



int main() {
	int sum = 0;
	int number1;
	int number2;

	for (int n = 1; n <= MAX; ++n) {
		number1 = properDivisorSum(n);
		number2 = properDivisorSum(number1);

		if (number2 == n && number1 != number2) {
			sum += n;
		}

	}
	
	std::cout << sum << std::endl;

	return 0;
}