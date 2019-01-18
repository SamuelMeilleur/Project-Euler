#include <iostream>
#include <vector>
#include <cmath>
#define MAX 10000

using namespace std;

unsigned int nDigits(unsigned int number) {
	unsigned int count = 0;
	while(number != 0) {
		++count;
		number /= 10;
	}
	return count;
}

int main() {
	unsigned int largestPandigital = 0;
	for (unsigned int n = 1; n < MAX ; n += 2) { //pair numbers will always give a product that is pair.
		vector<bool> digitsSeen(9, 0);
		bool isPandigital = true;
		unsigned nDigitsTotal = 0;
		unsigned int concatenatedNum = 0;
		for (unsigned int multiplier = 1; ; ++multiplier) {
			unsigned int product = n * multiplier;
			unsigned int temp = product;

			unsigned int nDigitsProduct = nDigits(product);
			nDigitsTotal += nDigitsProduct;

			for (int i = 0; i < nDigitsProduct; ++i) {
				if (temp % 10 == 0 || digitsSeen[temp % 10 - 1] == true) {
					isPandigital = false;
					break;
				}
				digitsSeen[temp % 10 - 1] = true;
				temp /= 10;
			}
			concatenatedNum = concatenatedNum * pow(10, nDigitsProduct) + product;
			if (!isPandigital || nDigitsTotal > 9)
				break;

			if (nDigitsTotal == 9 && concatenatedNum > largestPandigital) {
				largestPandigital = concatenatedNum;
				break;
			}
		}
	}

	cout << largestPandigital << endl;




	return 0;
}