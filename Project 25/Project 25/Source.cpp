#include <iostream>
#include <vector>
#define NB_DIGITS 1000

using namespace std;

vector<unsigned int> add(const vector<unsigned int>& a, const vector<unsigned int>& b) {
	vector<unsigned int> result = b;
	unsigned int carry = 0;
	for (int i = 0; i < result.size(); ++i) {
		result[i] += a[i] + carry;
		if (result[i] > 9) {
			result[i] -= 10;
			carry = 1;
		}
		else 
			carry = 0;
	}
	return result;
}


int main() {
	vector<unsigned int> a(NB_DIGITS);
	vector<unsigned int> b(NB_DIGITS);
	a.front() = 1;
	b.front() = 1;
	unsigned int fibonacciIndex = 2;
	while (b[NB_DIGITS - 1] == 0) {
		++fibonacciIndex;
		vector<unsigned int> next = add(a, b);
		a = b;
		b = next;
	}
	
	cout << fibonacciIndex;

	return 0;
}