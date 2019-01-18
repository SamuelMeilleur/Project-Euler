#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction::Fraction(int n = 1, int d = 1) : numerator_(n), denominator_(d) { __check(); }
	void setNumerator(int n) { numerator_ = n; }
	void setDenominator(int d) { denominator_ = d; }
	int getNumerator() const { return numerator_; }
	int getDenominator() const { return denominator_; }
	void __sign();
	void __invalidDivision() const;
	void __check();
	
	int lowestCommonDenominator(const Fraction&) const;
	bool simplify();

	Fraction& operator +(const Fraction&);
	Fraction& operator -(const Fraction&);
	Fraction& operator *(const Fraction&);
	Fraction& operator /(const Fraction&);
	Fraction& operator +(int);
	Fraction& operator -(int);
	Fraction& operator *(int);
	Fraction& operator /(int);
	void operator +=(const Fraction&);
	void operator -=(const Fraction&);
	void operator *=(const Fraction&);
	void operator /=(const Fraction&);
	void operator +=(int);
	void operator -=(int);
	void operator *=(int);
	void operator /=(int);
	bool operator >(const Fraction&) const;
	bool operator <(const Fraction&) const;
	bool operator >=(const Fraction&) const;
	bool operator <=(const Fraction&) const;
	bool operator ==(const Fraction&) const;
	bool operator !=(const Fraction&) const;
	bool operator >(int) const;
	bool operator <(int) const;
	bool operator >=(int) const;
	bool operator <=(int) const;
	bool operator ==(int) const;
	bool operator !=(int) const;
	void afficher(ostream&) const;
	friend ostream& operator << (ostream&, const Fraction&);

	friend Fraction& operator + (int, Fraction&);
	friend Fraction& operator - (int, Fraction&);
	friend Fraction& operator * (int, Fraction&);
	friend Fraction& operator / (int, Fraction&);

	friend bool operator > (int, Fraction&);
	friend bool operator < (int, Fraction&);
	friend bool operator >= (int, Fraction&);
	friend bool operator <= (int, Fraction&);
	friend bool operator == (int, Fraction&);
	friend bool operator != (int, Fraction&);

private:
	int numerator_;
	int denominator_;
};

































#endif