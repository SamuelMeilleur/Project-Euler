#include<iostream>
#define SIZE 1001

using namespace std;

int main() {
	unsigned long long
		total = 1,
		corner1 = 0, 
		corner2 = 0, 
		corner3 = 0, 
		corner4 = 1;

	for (unsigned long long n = 1; n <= (SIZE - 1) / 2; ++n) {
		corner1 = corner4 + (n * 2);
		corner2 = corner1 + (n * 2);
		corner3 = corner2 + (n * 2);
		corner4 = corner3 + (n * 2);
		total += corner1 + corner2 + corner3 + corner4;
	}

	cout << "Diagonals: " << total << endl;


	return 0;
}