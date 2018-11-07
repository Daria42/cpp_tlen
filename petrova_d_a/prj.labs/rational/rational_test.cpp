#include "rational.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
void test(string test, T rhs, T ans) {
	cout << test << ": " << rhs << " ";
	if (rhs == ans) cout << "OK";
	else cout << "WA: " << ans;
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "---�����������---" << endl;
	Rational a;
	test("�������� �� ���������", a, Rational(0));
	a = Rational(2, 8);
	test("�������� � ��������� ����� � �������� = ", a, Rational(1, 4));
	a = Rational(6);
	test("�������� ����� �� ������ �����", a, Rational(6, 1));
	a = Rational(6, -3);
	test("������������� �����", a, Rational(-2, 1));
	a = Rational(1, 2);
	cout << endl;

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
	cout << endl;

	cout << "---����������---" << endl;
	try { a / Rational(0); }
	catch (runtime_error e) { cout << "������ ������ �� 0!" << endl; }
	cout << endl;
	return 0;
}