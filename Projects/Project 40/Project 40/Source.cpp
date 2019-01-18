#include <iostream>
#include <cmath>



int main() {
	int lastIndex = 1000000;		//last index of the irrational number to find
	
	int digitIndex = 1;
	int result = 1;
	for (int n = 1; digitIndex <= lastIndex; n++) {
		int number = n;
		int nDigits = log10(number) + 1;

		for(int i = 0; i < nDigits; i++) {
			double power = log10(digitIndex);
			if (power == int(power)) {  //the index is a power of 10
				result *= number / int(pow(10.0, floor(log10(number))));
			}
			if (number != 0) {
				number = number % int(pow(10.0, floor(log10(number))));		//removes left-most digit of number
			}
			digitIndex++;
		}

	}

	std::cout << result << std::endl;

	system("pause");
}