#include <iostream>
#include <sstream>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

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

	void normal();

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

int main() {
	using namespace std;
	Rational a(0), b(1, 2), c(3, 4), d(7, 4), e(0), f(2, 5), g(8), h(42);
	a += b;
	b -= c;
	c /= d;
	e *= f;
	cout << a + b << " " << c - d << " " << e * f << " " << g / h << endl;
	cin >> a >> b;
	cout << a + b << " " << a - b << " " << a * b << " " << a / b << endl;
	return 0;
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