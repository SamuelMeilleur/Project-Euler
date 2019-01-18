#include <iostream>
#include <cmath>
#define SIZE 1000000
using namespace std;

int rotation(int number[], int size) {
	int temp = number[0];
	
	for (int i = 0; i < size - 1; ++i) {
		number[i] = number[i + 1];
	}
	number[size - 1] = temp;
	return 0;
}

bool isPrime(int number) {
	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0)
			return false;
	}
	return true;
}

int nbDigits(int number) {
	int digits = 0;
	while (number != 0) {
		number /= 10;
		digits++;
	}
	return digits;
}

int arrayToNum(int arr[], int size) {
	int number = arr[0];
	for (int i = 1; i < size; ++i) {
		number += pow(10,i) * arr[i];
	}
	return number;
}

int main() {
	
	int* numbers;
	int count = 0;
	for (int n = 2; n < SIZE; ++n) {
		int number = n;
		int digits = nbDigits(n);
		numbers = new int[digits];
		for (int i = 0; i < digits; ++i) {
			numbers[i] = number % 10;
			number /= 10;
		}
		number = n;
		bool isCircularPrime = true;
		if (isPrime(number)) {
			for (int i = 1; i < digits; i++) {
				rotation(numbers, digits);
				number = arrayToNum(numbers, digits);
				if (!isPrime(number)) {
					isCircularPrime = false;
					break;
				}
				
			}
			if (isCircularPrime) 
				count++;
			
		}
	}
	
	cout << count  << endl;
	
	return 0;
}