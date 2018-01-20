#include <iostream>
#include <cmath>
#include <fstream>

int main() {
	const int MAX_SIZE = 15;
	int** triangle = new int*[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; ++i) {
		triangle[i] = new int[i + 1];
	}
	
	std::fstream file;
	file.open("triangle.txt", std::ios::in);
	
	int n = 0;
	while (!file.eof()) {
		for (int i = 0; i <= n; ++i) {
			file >> triangle[n][i];
		}
		++n;
	}
	for (int i = MAX_SIZE - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (triangle[i][j] > triangle[i][j + 1])
				triangle[i - 1][j] += triangle[i][j];
			else
				triangle[i - 1][j] += triangle[i][j + 1];
		}
		delete[] triangle[i];
	}
	
	std::cout << triangle[0][0] << '\n';
	delete[] triangle[0];
	delete[] triangle;
	
	return 0;
}