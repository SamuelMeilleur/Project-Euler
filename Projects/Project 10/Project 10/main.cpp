#include <iostream>	
#include <cmath>

int main(){
	long long num = 2000000;
	bool isPrime = true;
	long long sum = 2;

	for (int n = 3; n < num; n+=2) {
		isPrime = true;
		for (int i = 2; i*i <= n; ++i) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			sum += n;
	}


	std::cout << sum << std::endl;

	return 0;
}