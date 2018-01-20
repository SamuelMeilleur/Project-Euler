#include <iostream>
#include "functions.h"

int main() {
	enum Months {
		JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER  
	};

	
	int counter = 0;
	int daysInMonth, daysPassed = 2;
	for (int year = 1901; year <= 2000; ++year) {
		for (int month = JANUARY; month <= DECEMBER; ++month) {
			if (month == APRIL || month == JUNE || month || month == SEPTEMBER || month == NOVEMBER)
				daysInMonth = 30;
			else if (month == FEBRUARY)
				if (isLeapYear(year))
					daysInMonth = 29;
				else
					daysInMonth = 28;
			else
				daysInMonth = 31;

			if (daysPassed % 7 == 0)
				++counter;

			daysPassed += daysInMonth;
		}

	}

	std::cout << counter << std::endl;

	return 0;
}