#include <iostream>
#include <vector>
#define RANGE 1000
#define NOT_SEEN 0

using namespace std;


unsigned int findCycleLength(unsigned int number) {
	if (number == 0)
		return 0;
	vector<unsigned int> remainderSeen(number - 1, NOT_SEEN);
	unsigned int cycleLength = 1;
	unsigned int dividend = 1;
	while (true) {
		unsigned int remainder = dividend % number;
		if (remainder == 0)
			return 0;
		if (remainderSeen[remainder - 1] != NOT_SEEN)
			return cycleLength - remainderSeen[remainder - 1];

		remainderSeen[remainder - 1] = cycleLength;
		dividend = remainder * 10;
		++cycleLength;
	}
}



int main() {
	unsigned int longestCycle = 0;
	unsigned int value = 0;
	for (int i = RANGE - 1; i >= 0; --i) {
		if (longestCycle >= i)
			break;
		if (findCycleLength(i) > longestCycle) {
			longestCycle = findCycleLength(i);
			value = i;
		}
	}
	
	cout << longestCycle << '\t' << value;
	
	


	return 0;
}