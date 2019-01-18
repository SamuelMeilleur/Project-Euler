#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int number) {
	if (number == 2) {
		return true;
	}
	if (number % 2 == 0) {
		return false;
	}
	for (int i = 3; i * i <= number; i += 2) {
		if (number % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	string permutation = "987654321";

	while (!isPrime(stoi(permutation))) {
		// if last possible permutation
		if (!prev_permutation(permutation.begin(), permutation.end())) {
			permutation = permutation.substr(1);	// remove biggest digit
		}
	}
	cout << permutation << endl;

	return 0;
}