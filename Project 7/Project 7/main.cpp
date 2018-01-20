#include <iostream>
#include <cmath>

int main() {
	const int num_of_prime = 10001;
	int primeArray[num_of_prime];
	int count = 0;
	bool isPrime;

	for (int n = 2; count < num_of_prime; ++n) {
		isPrime = true;
		for (int i = 2; i < n; ++i) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primeArray[count++] = n;
		}
	}
	

	std::cout << primeArray[num_of_prime - 1] << std::endl;

	return 0;
}