#include <iostream>
#include <sstream>

class Complex {
public:
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }

	std::ostream& writeTo(std::ostream& ostrm);
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char seperator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, Complex& rhs) { return rhs.writeTo(ostrm); }
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) { return rhs.readFrom(istrm); }

int main() {
	using namespace std;
	Complex a(0), b(1, 2), c(3, 4), d(7, 4), e(10), f(2, 5), g(8), h(42);
	a += b;
	b -= c;
	c /= d;
	e *= f;
	cout << a + b << " " << c - d << " " << e * f << " " << g / h << endl;
	cin >> a >> b;
	cout << a + b << " " << a - b << " " << a * b << " " << a / b << endl;
	return 0;
}

Complex::Complex(const double real) : Complex(real, 0) {}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {};

Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re; im += rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res += rhs;
	return res;
}

Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re; im -= rhs.im;
	return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res -= rhs;
	return res;
}

Complex& Complex::operator*=(const Complex& rhs) {
	re = re + rhs.re - im * rhs.im; im += rhs.im;
	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res *= rhs;
	return res;
}

Complex& Complex::operator/=(const Complex& rhs) {
	double tre = re, tim = im;
	re = (tre * rhs.re + tim * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = (rhs.re * tim - tre * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res /= rhs;
	return res;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) {
	ostrm << leftBrace << re << seperator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good() && Complex::leftBrace == leftBrace && Complex::seperator == seperator && Complex::rightBrace == rightBrace) {
		re = real;
		im = imaginary;
	}
	else if (istrm.good()) istrm.setstate(std::ios_base::failbit);
	return istrm;
}