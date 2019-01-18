#include <iostream>
#include <vector>
#include "Fraction.h"

using namespace std;

int main() {
	vector<Fraction> fractions;
	for (double n = 10; n < 100; ++n) {
		for (double d = n + 1; d < 100; ++d) {
			double numerator[2] = { int(n) % 10, int(n / 10) };
			double denominator[2] = { int(d) % 10, int(d / 10) };
			double fraction = n / d;
			
			if (numerator[0] == denominator[1] && 
				denominator[0] != 0 &&
				numerator[1] / denominator [0] == fraction) {
				fractions.push_back(Fraction(n, d));
			}
			if (numerator[1] == denominator[0] &&
				denominator[1] != 0 &&
				numerator[0] / denominator[1] == fraction) {
				fractions.push_back(Fraction(n, d));
			}
		}
	}
	
	Fraction total = fractions[0] * fractions[1] * fractions[2] * fractions[3];
	total.simplify();
	cout << total << endl;
}

