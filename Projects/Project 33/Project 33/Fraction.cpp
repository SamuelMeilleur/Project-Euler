#include "Fraction.h"
//#include <exception>
//#include <stdexcept>
using namespace std;

void Fraction::__sign() {
	if (numerator_ < 0 && denominator_ < 0) {
		numerator_ *= -1;
		denominator_ *= -1;
	}
	else if (denominator_ < 0) {
		numerator_ *= -1;
		denominator_ *= -1;
	}
}
void Fraction::__invalidDivision() const{
	if (denominator_ == 0) {
		throw(domain_error("Divison by 0!"));
	}
}
void Fraction::__check(){
	__sign();
	try {
		__invalidDivision();
	}
	catch (domain_error e) {
		cerr << e.what() << endl;
	}
}

int Fraction::lowestCommonDenominator(const Fraction& f) const {
	int n1 = denominator_;
	int n2 = f.denominator_;
	while (n1 != n2) {
		n1 > n2 ?
			n1 -= n2 : n2 -= n1;
	}
	int gcd = n1;
	return denominator_ * f.denominator_ / gcd;
}

bool Fraction::simplify() {
	int n1 = numerator_;
	int n2 = denominator_;
	int temp = numerator_;
	while (n1 != n2) {
		n1 > n2 ?
			n1 -= n2 : n2 -= n1;
	}
	numerator_ /= n1;
	denominator_ /= n1;
	__check();
	return temp != numerator_;
}

Fraction& Fraction::operator +(const Fraction& f) {
	int lcd = this->lowestCommonDenominator(f);
	numerator_ *= lcd / denominator_;
	denominator_ = lcd;
	numerator_ += f.numerator_ * lcd / f.denominator_;
	__check();
	return *this;
}

Fraction& Fraction::operator -(const Fraction& f) {
	int lcd = this->lowestCommonDenominator(f);
	numerator_ *= lcd / denominator_;
	denominator_ = lcd;
	numerator_ -= f.numerator_ * lcd / f.denominator_;
	__check();
	return *this;
}
Fraction& Fraction::operator *(const Fraction& f) {
	numerator_ *= f.numerator_;
	denominator_ *= f.denominator_;
	__check();
	return *this;
}

Fraction& Fraction::operator /(const Fraction& f) {
	numerator_ *= f.denominator_;
	denominator_ *= f.numerator_;
	__check();
	return *this;
}

Fraction& Fraction::operator +(int n) {
	n *= denominator_;
	numerator_ += n;
	__check();
	return *this;
}
Fraction& Fraction::operator -(int n) {
	n *= denominator_;
	numerator_ -= n;
	__check();
	return *this;
}

Fraction& Fraction::operator *(int n) {
	numerator_ *= n;
	__check();
	return *this;
}

Fraction& Fraction::operator /(int n) {
	denominator_ *= n;
	__check();
	return *this;
}

void Fraction::operator +=(const Fraction& f) {
	*this = *this + f;
}
void Fraction::operator -=(const Fraction& f) {

}
void Fraction::operator *=(const Fraction& f) {

}
void Fraction::operator /=(const Fraction& f) {

}

void Fraction::operator +=(int n) {

}
void Fraction::operator -=(int n) {

}
void Fraction::operator *=(int n) {

}
void Fraction::operator /=(int n) {

}

bool Fraction::operator >(const Fraction& f) const {
	double d1 = numerator_ / denominator_;
	double d2 = f.numerator_ / f.denominator_;
	return d1 > d2;
}
bool Fraction::operator < (const Fraction& f) const {
	double d1 = numerator_ / denominator_;
	double d2 = f.numerator_ / f.denominator_;
	return d1 < d2;
}
bool Fraction::operator >=(const Fraction& f) const {
	return !(*this < f);
}
bool Fraction::operator <=(const Fraction& f) const {
	return !(*this > f);
}
bool Fraction::operator ==(const Fraction& f) const {
	double d1 = numerator_ / denominator_;
	double d2 = f.numerator_ / f.denominator_;
	return d1 == d2;
}
bool Fraction::operator !=(const Fraction& f) const {
	return !(*this == f);
}

bool Fraction::operator >(int n) const{
	n *= denominator_;
	return numerator_ > n;
}
bool Fraction::operator <(int n) const{
	n *= denominator_;
	return numerator_ < n;
}
bool Fraction::operator >=(int n) const{
	return !(*this < n);
}
bool Fraction::operator <=(int n) const{
	return !(*this > n);
}
bool Fraction::operator ==(int n) const{
	n *= denominator_;
	return numerator_ == n;
}
bool Fraction::operator !=(int n) const{
	return !(*this == n);
}

void Fraction::afficher(ostream& out) const {
	out << numerator_ << '/' << denominator_;
}

ostream& operator << (ostream& out, const Fraction& f) {
	f.afficher(out);
	return out;
}

Fraction& operator +(int n, Fraction& f) {
	return f + n;
}
Fraction& operator -(int n, Fraction& f) {
	return f - n;
}						 
Fraction& operator *(int n, Fraction& f) {
	return f * n;
}						 
Fraction& operator /(int n, Fraction& f) {
	return f / n;
}

bool operator >(int n, Fraction& f) {
	return f < n;
}
bool operator <(int n, Fraction& f) {
	return f > n;
}
bool operator >=(int n, Fraction& f) {
	return f <= n;
}
bool operator <=(int n, Fraction& f) {
	return f >= n;
}
bool operator ==(int n, Fraction& f) {
	return f == n;
}
bool operator !=(int n, Fraction& f) {
	return f != n;
}