#include <iostream>
#include <cmath>
#include "Functions.h"
int main() {
	const int maxNumber = pow(10, 3);
	int largestPalindrome = 0;

	for (int i = 0; i < maxNumber; ++i) {
		for (int j = i; j < maxNumber; j++) {
			int product = i*j;
			if (isPalindrome(product) && product > largestPalindrome)
				largestPalindrome = product;
		}
	}

	std::cout << largestPalindrome << std::endl;

	return 0;
}