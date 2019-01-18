#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

int main() {
	std::fstream file;
	file.open("numbers.txt", std::ios::in);
	if (!file.fail()) {
		double sum = 0;
		std::string numberStr;
		while (!file.eof()) {
			std::getline(file, numberStr);
			sum += stod(numberStr);
		}
		std::cout << std::setprecision(15);
		std::cout << sum << std::endl;
	}
	else
		std::cout << "Can't open file!.\n";

	return 0;
}