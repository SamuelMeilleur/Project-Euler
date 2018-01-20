#include <iostream>
#define MAX 200

using namespace std;

int main() {
	unsigned long long count = 0;
	for (int p200 = 0; p200 <= MAX; p200 += 200)
		for (int p100 = 0; p100 <= MAX; p100 += 100) 
			for (int p50 = 0; p50 <= MAX; p50 += 50) 
				for (int p20 = 0; p20 <= MAX; p20 += 20) 
					for (int p10 = 0; p10 <= MAX; p10 += 10) 
						for (int p5 = 0; p5 <= MAX; p5 += 5) 
							for (int p2 = 0; p2 <= MAX; p2 += 2) 
								for (int p1 = 0; p1 <= MAX; p1 += 1) 
									if (p1 + p2 + p5 + p10 + p20 + p50 + p100 + p200 == 200) {
										count++;
									}
	
	cout << count << endl;

	return 0;
}


