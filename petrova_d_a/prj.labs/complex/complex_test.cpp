#include "complex.h"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
void test(string test, T rhs, T ans) {
	cout << test << ": " << rhs << " ";
	if (rhs == ans) cout << "OK";
	else {
		cout << "NO: " << ans;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "---Конструктор---" << endl;
	Complex a;
	test("Значение по умолчанию", a, Complex(0, 0));
	a = Complex(2, 8);
	test("Создание комплексного числа, оператор = ", a, Complex(2, 8));
	a = Complex(6.0);
	test("Создание комплексного числа по действительной части", a, Complex(6, 0));
	cout << endl;
	
	/*a = Complex(1, 2);
	cout << "---Арифметические операции---" << endl;
	Rational b(2);
	test("Сумма", a + b, Rational(5, 2));
	test("Разность", a - b, Rational(-3, 2));
	test("Умножение", a * b, Rational(1));
	test("Деление", a / b, Rational(1, 4));
	test("Присваивание суммы", a += b, Rational(5, 2));
	test("Присваивание разности", a -= b, Rational(1, 2));
	test("Присваивание произведения", a *= b, Rational(1));
	test("Присваивание частного", a /= b, Rational(1, 2));
	cout << endl;

	cout << "---Смешанная арифметика---" << endl;
	int k = 2;
	test("Сумма", a + k, Rational(5, 2));
	test("Разность", a - k, Rational(-3, 2));
	test("Умножение", a * k, Rational(1));
	test("Деление", a / k, Rational(1, 4));
	test("Присваивание суммы", a += k, Rational(5, 2));
	test("Присваивание разности", a -= k, Rational(1, 2));
	test("Присваивание произведения", a *= k, Rational(1));
	test("Присваивание частного", a /= k, Rational(1, 2));

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
	cout << k + a << " " << k + b << " " << k * c << " " << k / d << endl;*/
	return 0;
}