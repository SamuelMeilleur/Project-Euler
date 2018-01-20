#include <iostream>
#include <string>
#include <cmath>

int divisorCounter(int n);


int main() {
	int triangleNumber = 0;
	int i = 1;
	while (divisorCounter(triangleNumber) <= 500) {
		triangleNumber += i++;
	}
	
	std::cout << triangleNumber << std::endl;

	return 0;
}



int divisorCounter(int number){
	int counter = 0;
	for (int i = 1; i*i <= number; ++i) {
		if (number%i == 0) {
			counter += 2;
		}
	}

	return counter;
}

