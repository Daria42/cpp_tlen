#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>

class Rational {
public:
	Rational() {}
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);
	bool operator==(const Rational& rhs) const { return (num * rhs.den == rhs.den * num); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }

	std::ostream& writeTo(std::ostream& ostrm);
	std::istream& readFrom(std::istream& istrm);

	static const char seperator{ '/' };

	int num{ 0 };
	int den{ 1 };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, Rational& rhs) { return rhs.writeTo(ostrm); }
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.readFrom(istrm); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	using namespace std;
	Rational a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a - c * b) / d << endl;
	return 0;
}

Rational::Rational(const int numerator): Rational(numerator, 1) {}

Rational::Rational(const int numerator, const int denominator) : num(numerator), den(denominator) {};

Rational& Rational::operator+=(const Rational& rhs) {
	int temp = gcd(den, rhs.den);
	num = num * (rhs.den / temp) + rhs.num * (den / temp);
	den = den * rhs.den / temp;
	int mult = gcd(num, den);
	num /= mult; den /= mult;
	if (den < 0) {
		den *= -1;
		num *= -1;
	}
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
	int mult = gcd(num, den);
	num /= mult; den /= mult;
	if (den < 0) {
		den *= -1;
		num *= -1;
	}
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
	int mult = gcd(num, den);
	num /= mult; den /= mult;
	if (den < 0) {
		den *= -1;
		num *= -1;
	}
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
	int mult = gcd(num, den);
	num /= mult; den /= mult;
	if (den < 0) {
		den *= -1;
		num *= -1;
	}
	return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational res = lhs;
	res /= rhs;
	return res;
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
	}
	else if (istrm.good()) istrm.setstate(std::ios_base::failbit);
	return istrm;
}