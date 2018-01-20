#include <iostream>	
#include <cmath>

int main() {
	int a = 0, b = 0;
	int c = 0;
	float temp;

	for (int i = 0; i < 1000; ++i) {
		++a;
		b = 0;
		for (int j = 0; j < 1000; ++j) {
			++b;
			temp = sqrt(a*a + b*b);
			if (floor(temp) == temp)
				c = temp;
			if (a + b + c == 1000 && ((a*a + b*b) == c*c))
				break;
		}
		if (a + b + c == 1000 && ((a*a + b*b) == c*c))
			break;
	}

	if (a + b + c == 1000) {
		std::cout << a * b * c << std::endl;
		std::cout << a << '\t' << b << '\t' << c << std::endl;
	}



	return 0;
}