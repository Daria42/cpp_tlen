#include "complex.h"
#include <iostream>
#include <sstream>

int main() {
	using namespace std;
	Complex a(0), b(1, 2), c(3, 4), d(7, 4), e(10), f(2, 5), g(8), h(42);
	a += b;
	b -= c;
	c /= d;
	e *= f;
	cout << a + b << " " << c - d << " " << e * f << " " << g / h << endl;
	double k = 2;
	a += k;
	b /= k;
	c -= k;
	d *= k;
	cout << a << " " << b << " " << c << " " << d << endl;
	cout << a + k << " " << b + k << " " << c * k << " " << d / k << endl;
	cout << k + a << " " << k + b << " " << k * c << " " << k / d << endl;
	return 0;
}