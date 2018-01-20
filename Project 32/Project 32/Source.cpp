#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

int nbOfDigits(int number) {
	int nbDigits = 0;
	while (number != 0) {
		number = number / 10;
		nbDigits++;
	}
	return nbDigits;
}

bool isPandigital(int n1, int n2, int n3) {
	vector<int> digits(9, 0);
	while (n1 != 0) {
		int digit = n1 % 10;
		if (digit == 0 || digits[digit - 1] != 0)
			return false;
		digits[digit - 1] = digit;
		n1 /= 10;
	}
	while (n2 != 0) {
		int digit = n2 % 10;
		if (digit == 0 || digits[digit - 1] != 0)
			return false;
		digits[digit - 1] = digit;
		n2 /= 10;
	}
	while (n3 != 0) {
		int digit = n3 % 10;
		if (digit == 0 || digits[digit - 1] != 0)
			return false;
		digits[digit - 1] = digit;
		n3 /= 10;
	}
	return true;
}

int main() {
	vector<int> products;
	for (int multiplicand = 1; multiplicand < 10000; ++multiplicand) {
		for (int multiplier = 1; ; ++multiplier) {	//break condition in loop
			int product = multiplicand * multiplier;
			int nbDigits = nbOfDigits(multiplicand) + nbOfDigits(multiplier) + nbOfDigits(product);
			if (nbDigits > 9)
				break;
			if (nbDigits == 9) {
				if (isPandigital(multiplicand, multiplier, product)) {
					if (find(products.begin(), products.end(), product) == products.end())
						products.push_back(product);
				}
			}

		}
	}
	unsigned long long sum = 0;
	for (int i = 0; i < products.size(); ++i) {
		sum += products[i];
	}
	
	cout << sum << endl;

	return 0;
}