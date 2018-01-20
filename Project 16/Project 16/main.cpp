#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>	


int main() {
	const int exponent = 1000;
	const int nbDigits = ceil(1000 * log(2) / log(10));

	std::vector<int> digits(nbDigits);
	digits.front() = 1;
	int carry = 0;
	
	for (int n = 0; n < exponent; ++n) {
		for (int i = 0; i < nbDigits; ++i) {
			digits[i] = digits[i] + digits[i] + carry;
			if (digits[i] >= 10) {
				carry = 1;
				digits[i] = digits[i] % 10;
			}
			else
				carry = 0;
		}
	}

	std::cout << std::accumulate(digits.begin(), digits.end(), 0) << std::endl;

}

	
