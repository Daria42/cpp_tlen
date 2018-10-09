#include "rational.h"
#include <iostream>
#include <sstream>

int gcd (int a, int b) {
	int temp;
	while (b) {
		a %= b;
		temp = a;
		a = b;
		b = temp;
	}
	return a;
}

Rational::Rational(const int numerator): Rational(numerator, 1) {}

Rational::Rational(const int numerator, const int denominator) : num(numerator), den(denominator) {
	(*this).normal();
};

Rational& Rational::operator+=(const Rational& rhs) {
	int temp = gcd(den, rhs.den);
	num = num * (rhs.den / temp) + rhs.num * (den / temp);
	den = den * rhs.den / temp;
	(*this).normal();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational res = lhs;
	res += rhs;
	return res;
}

Rational& Rational::operator-=(const Rational& rhs) {
	int temp = gcd(den, rhs.den);
	num = num * (rhs.den / temp) - rhs.num * (den / temp);
	den = den * rhs.den / temp;
	(*this).normal();
	return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational res = lhs;
	res -= rhs;
	return res;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num = num * rhs.num;
	den = den * rhs.den;
	(*this).normal();
	return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational res = lhs;
	res *= rhs;
	return res;
}

Rational& Rational::operator/=(const Rational& rhs) {
	num = num * rhs.den;
	den = den * rhs.num;
	(*this).normal();
	return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational res = lhs;
	res /= rhs;
	return res;
}

Rational operator+(const Rational& lhs, const int& rhs) { return (lhs + Rational(rhs)); };
Rational operator-(const Rational& lhs, const int& rhs) { return (lhs - Rational(rhs)); };
Rational operator*(const Rational& lhs, const int& rhs) { return (lhs * Rational(rhs)); };
Rational operator/(const Rational& lhs, const int& rhs) { return (lhs / Rational(rhs)); };

Rational operator+(const int& lhs, const Rational& rhs) { return (Rational(lhs) + rhs); };
Rational operator-(const int& lhs, const Rational& rhs) { return (Rational(lhs) - rhs); };
Rational operator*(const int& lhs, const Rational& rhs) { return (Rational(lhs) * rhs); };
Rational operator/(const int& lhs, const Rational& rhs) { return (Rational(lhs) / rhs); };


void Rational::normal() {
	if (den == 0) num = 0;
	if (!(num * den)) den = 1;
	if (den < 0) {
		den *= -1;
		num *= -1;
	}
	int mult = gcd(abs(den), num);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) {
	if (num != 0) ostrm << num << seperator << den;
	else ostrm << 0;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	int numerator(0);
	char comma(0);
	int denumerator(1);
	istrm >> numerator >> comma >> denumerator;
	if (Rational::seperator == seperator) {
		num = numerator;
		den = denumerator;
		(*this).normal();
	}
	else if (istrm.good()) istrm.setstate(std::ios_base::failbit);
	return istrm;
}