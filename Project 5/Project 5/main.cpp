#include <iostream>
#include <cmath>

int main() {
	int smallestDivisbleNum = 0;
	int count = 20;
	while (!smallestDivisbleNum) {
		int temp = count;
		for (int i = 20; i > 0; --i) {
			if (count % i != 0) {
				count += 20;
				break;
			}
		}
		if(temp == count)
			smallestDivisbleNum = count;
	}

	std::cout << smallestDivisbleNum << std::endl;

	return 0;
}