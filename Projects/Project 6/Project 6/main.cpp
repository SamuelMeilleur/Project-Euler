#include <iostream>
#include <cmath>

int main() {
	const int max_num = 100;
	
	int sumOfSquares = 0;
	for (int i = max_num; i > 0; --i) {
		sumOfSquares += i*i;
	}
	
	int squareOfSum = 0;
	for (int i = max_num; i > 0; --i) {
		squareOfSum += i;
	}
	squareOfSum *= squareOfSum;


	std::cout << squareOfSum - sumOfSquares << std::endl;
	
	return 0;
}