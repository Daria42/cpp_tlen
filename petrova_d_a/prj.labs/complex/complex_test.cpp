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

	cout << "---�����������---" << endl;
	Complex a;
	test("�������� �� ���������", a, Complex(0, 0));
	a = Complex(2, 8);
	test("�������� ������������ �����, �������� = ", a, Complex(2, 8));
	a = Complex(6.0);
	test("�������� ������������ ����� �� �������������� �����", a, Complex(6, 0));
	cout << endl;
	
	/*a = Complex(1, 2);
	cout << "---�������������� ��������---" << endl;
	Rational b(2);
	test("�����", a + b, Rational(5, 2));
	test("��������", a - b, Rational(-3, 2));
	test("���������", a * b, Rational(1));
	test("�������", a / b, Rational(1, 4));
	test("������������ �����", a += b, Rational(5, 2));
	test("������������ ��������", a -= b, Rational(1, 2));
	test("������������ ������������", a *= b, Rational(1));
	test("������������ ��������", a /= b, Rational(1, 2));
	cout << endl;

	cout << "---��������� ����������---" << endl;
	int k = 2;
	test("�����", a + k, Rational(5, 2));
	test("��������", a - k, Rational(-3, 2));
	test("���������", a * k, Rational(1));
	test("�������", a / k, Rational(1, 4));
	test("������������ �����", a += k, Rational(5, 2));
	test("������������ ��������", a -= k, Rational(1, 2));
	test("������������ ������������", a *= k, Rational(1));
	test("������������ ��������", a /= k, Rational(1, 2));

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