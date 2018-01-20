#include <iostream>
#define MAX 2500000

using namespace std;

int factorial(int number) {
	if (number == 0)
		return 1;
	else
		return number * factorial(number - 1);
}

int main() {
	int factorials[10];
	for (int i = 0; i < 10; ++i) {
		factorials[i] = factorial(i);
	}
	int sum = 0;
	for (int n = 10; n < MAX; ++n) {
		int number = n;
		int factorialSum = 0;
		while (number != 0) {
			factorialSum += factorials[number % 10];
			number /= 10;
			if (factorialSum > n)
				break;
		}
		if (factorialSum == n) {
			sum += factorialSum;
		}
	}
	cout << sum << endl;
}