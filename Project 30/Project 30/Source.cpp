#include <iostream>	
#include <vector>
#include <cmath>
#define POWER 5
#define MAX 355000

using namespace std;

typedef unsigned long long BigNumber;

vector<int> findDigits(BigNumber n) {
	vector<int> digits;
	while (n != 0) {
		digits.push_back(n % 10);
		n = n / 10;
	}

	return digits;
}


int main() {
	BigNumber total = 0;
	for (int n = 10; n < MAX; ++n) {
		vector<int> digits = findDigits(n);
		BigNumber sumOfPower = 0;
		for (int i = 0; i < digits.size(); ++i) {
			sumOfPower += pow(digits[i], POWER);
		}
		if (sumOfPower == n) {
			total += n;
			cout << n << '\n';
		}
	}
	
	cout << total << '\n';


	return 0;
}