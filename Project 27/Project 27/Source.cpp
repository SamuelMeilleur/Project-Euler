#include <iostream>
#define MAX 1000

using namespace std;


bool isPrime(int number) {
	if (number <= 1) 
		return false;

	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0)
			return false;
	}
	return true;
}


int main() {
	int valueA, valueB;
	unsigned int longestCycleLength = 0;

	for (int a = -MAX + 1; a < MAX; ++a) {
		for (int b = -MAX; b <= MAX; ++b) {
			unsigned int cycleLength = 0;
			int n = 0;
			int result;
			do {
				result = (n * n) + (a * n) + b;
				cycleLength++;
				n++;
			} while (isPrime(result));
				
			if (cycleLength > longestCycleLength) {
				longestCycleLength = cycleLength;
				valueA = a;
				valueB = b;
			}
			
		}

	}

	cout << "a: " << valueA << "\nb: " << valueB << "\nLength: " << longestCycleLength << "\na * b = " << valueA * valueB << endl;

	return 0;
}