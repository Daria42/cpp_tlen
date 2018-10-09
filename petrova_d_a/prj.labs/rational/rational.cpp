#include "rational.h"
#include <iostream>
#include <sstream>

//int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int gcd(int a, int b) {
	int ans = 1;
	for (int i = 2; i <= a / 2 && i <= b / 2; i++)
		if (a % i == 0 && b % i == 0)
			ans = i;
	return ans;
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
	ostrm << num << seperator << den;
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