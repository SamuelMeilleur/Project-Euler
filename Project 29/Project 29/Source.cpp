#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MIN 2
#define MAX 100

using namespace std;

int main() {
	vector<double> uniqueResults;

	for (double a = MIN; a <= MAX; ++a) {
		for (double b = MIN; b <= MAX; ++b) {
			double result = pow(a, b);
			
			if (find(uniqueResults.begin(), uniqueResults.end(), result) == uniqueResults.end())
				uniqueResults.push_back(result);

		}
	}

	cout << uniqueResults.size() << endl;
	
}