#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <ctime>
#define VALUE 1000000

using namespace std;

/**********LIST IMPLEMENTATION **************/
/*
list<int>::iterator _FindX(list<int>& digits) {
	list<int>::iterator largestX = digits.begin();
	auto it = digits.begin();
	auto temp = it;
	for (it; it != --digits.end(); ) {
		if (*it < *(++it)) {
			largestX = temp;
		} 
		++temp;
	}
	
	return largestX;
}

list<int>::iterator _FindY(list<int>& digits, list<int>::iterator largestX) {
	list<int>::iterator largestY = digits.begin();
	for (auto it = digits.begin(); it != digits.end(); ++it) {
		if (*it > *largestX) {
			largestY = it;
		}
	}

	return largestY;
}

void reverse(list<int>& digits, list<int>::iterator& pos) {
	list<int> newList;
	
	newList.splice(newList.begin(), digits, pos, digits.end());
	newList.reverse();
	
	digits.splice(digits.end(), newList);
}

void lexicographicPermutation(list<int>& digits) {
	auto largestX = _FindX(digits);
	auto largestY = _FindY(digits, largestX);
	iter_swap(largestX, largestY);
	reverse(digits, ++largestX);
}



int main() {
	clock_t t;
	t = clock();
	list<int> digits;
	for (int i = 0; i < 10; ++i) {
		digits.push_back(i);
	}
	for (int i = 1; i < VALUE; ++i) {
		lexicographicPermutation(digits);
	}	
	copy(digits.begin(), digits.end(), ostream_iterator<int>(cout));
	cout << endl;

	t = clock() - t;

	cout << t << endl;

	return 0;
}

*/

/**/
void afficher(int x[10]) {
	for (int i = 0; i < 10; ++i) {
		cout << x[i];
	}
	cout << endl;
}

int findX(int digits[10]) {
	int largestX = 0;
	for (int i = 0; i < 10; ++i) {
		if (digits[i] < digits[i + 1])
			largestX = i;
	}
	return largestX;
}

int findY(int digits[10], int posX) {
	int largestY = 0;
	for (int i = 0; i < 10; ++i) {
		if (digits[i] > digits[posX])
			largestY = i;
	}
	return largestY;
}

void reverse(int digits[10], int index) {
	int temp[10]; 
	for (int i = 0; i < 10; ++i) {
		temp[i] = digits[i];
	}
	for (int i = index; i < 10; ++i) {
		digits[i] = temp[9 - i + index];
	}
}

void lexicographicPermutation(int digits[10]) {
	int x = findX(digits);
	int y = findY(digits, x);
	int temp = digits[x];
	digits[x] = digits[y];
	digits[y] = temp;
	reverse(digits, x + 1);
}

int main() {
	clock_t t = clock();
	int digits[10];
	for (int i = 0; i < 10; i++) {
		digits[i] = i;
	}
	for (int n = 1; n < VALUE; ++n) {
		lexicographicPermutation(digits);
	}
	afficher(digits);

	t = clock() - t;

	cout << t << endl;

	return 0;
} //*/