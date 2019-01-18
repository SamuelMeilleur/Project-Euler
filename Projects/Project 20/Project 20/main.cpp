#include <iostream>
#include <vector>
#include <numeric>



int main() {
	int factorial = 100;
	int nbDigits = 500;
	std::vector<int> digits(nbDigits);
	digits.front() = 1;
	int carry = 0;

	for (int i = 2; i <= factorial; ++i) {
		for (int j = 0; j < digits.size(); ++j) {
			digits[j] = (digits[j] * i) + carry;
			if (digits[j] > 9) {
				carry = digits[j] / 10;
				digits[j] = digits[j] % 10;
			}
			else
				carry = 0;
		}

	}

	std::cout << std::accumulate(digits.begin(), digits.end(), 0) << '\n';

}
