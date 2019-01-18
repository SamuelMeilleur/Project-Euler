#pragma once
#include<list>
#include<iterator>

using namespace std;

class FindX {
public:
	FindX(list<int> digits) : digits_(digits) {};
	bool operator()(int x) {

	}

private:
	list<int> digits_;
};