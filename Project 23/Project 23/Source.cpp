#include <iostream>
#include <cmath>

#define MAX_VALUE 28123

using namespace std;

int sumOfDivisors(int number) {
	int sum = 1;
	for (int i = 2;  i * i <= number; ++i) {
		if (number % i == 0)
			sum += i + number / i;
	}
	int sqrtOfNumber = sqrt(number);
	if (sqrtOfNumber * sqrtOfNumber == number)
		sum -= sqrtOfNumber;
	return sum;
}

int main() { 
	
	const int abundantCount = 6965;
	int nbElements = 0;
	int abundantNumbers[abundantCount];
	for (int n = 1; n <= MAX_VALUE; ++n) {
		if (sumOfDivisors(n) > n)
			abundantNumbers[nbElements++] = n;
	}
	
	bool canBeWrittenAsAbundant[MAX_VALUE + 1] = {false};
	


	for (int i = 0; i <  abundantCount; ++i) {
		for (int j = i; j < abundantCount; ++j) {
			if (abundantNumbers[i] + abundantNumbers[j] <= MAX_VALUE) {
				canBeWrittenAsAbundant[abundantNumbers[i] + abundantNumbers[j]] = true;
			}
			else 
				break;
			
		}
	}
	
	long long sum = 0;// MAX_VALUE * (MAX_VALUE + 1) /2;
	for (int i = 0; i <= MAX_VALUE; ++i) {
		if (!canBeWrittenAsAbundant[i]) {
			sum += i;
		}
	}
	
	cout << sum << endl;
	return 0;
}