#include <iostream>
#include <cmath>

int main() {
	const int gridSize = 20;
	long long grid[gridSize + 1][gridSize + 1];
	for (int i = 0; i < gridSize; ++i) {
		grid[i][gridSize] = 1;
		grid[gridSize][i] = 1;
	}
	for (int i = gridSize - 1; i >= 0; --i) {
		for (int j = gridSize - 1; j >= 0; --j) {
			grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
		}
	}
	std::cout << grid[0][0] << std::endl;

	return 0;
}