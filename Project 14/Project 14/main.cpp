#include <iostream>
#include <cmath>

bool isEven(int number);

int main() {

	int longestChain = 0;
	int longestChainNumber = 0;
	int chain;
	long long number;
	for (int n = 1; n < 1000000; n+=2) {
		number = n;
		chain = 1;
		while (number != 1) {
			
			chain++;
			if (isEven(number)) 
				number /= 2;			
			else 
				(number *= 3)++;
		}
		if (chain > longestChain) {
			longestChain = chain;
			longestChainNumber = n;
		}
	}
	
	std::cout << longestChainNumber << std::endl;

	return 0;
}

bool isEven(int number) {
	return !(number % 2);
}