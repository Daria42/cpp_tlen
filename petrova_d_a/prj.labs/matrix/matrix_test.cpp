#include "rational.h"
#include <iostream>
#include <sstream>

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