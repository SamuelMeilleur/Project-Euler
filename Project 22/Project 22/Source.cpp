#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

class Counter {
public:
	Counter(long long& sum) :sum_(sum) {}
	void operator() (std::string name) {
		score_ = 0;
		++count_;
		for (int i = 0; i < name.size(); ++i) {
			score_ += name[i] - 64;
		}
		sum_ += score_ * count_;
	}
private:
	long long& sum_;
	int score_;
	static int count_;
};
int Counter::count_ = 0;




int main() {
	std::ifstream file("names.txt");
	if (!file.fail()) {
		std::string name;
		std::vector<std::string> list;
		char i;

		while (!file.eof()){
			name = "";
			file.ignore(1);
			while (char(file.peek()) != '\"'){
				file.get(i);
				name += i;
			}
			list.push_back(name);
			file.ignore(2);
		}
		std::sort(list.begin(), list.end());
		long long sum = 0;
		std::for_each(list.begin(), list.end(), Counter(sum));
	
		std::cout << sum << std::endl;
	}
	
	return 0;
}