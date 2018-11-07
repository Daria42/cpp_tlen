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

	cout << "---Конструктор---" << endl;
	Rational a;
	test("Значение по умолчанию", a, Rational(0));
	a = Rational(2, 8);
	test("Создание и сокрщение дроби и оператор = ", a, Rational(1, 4));
	a = Rational(6);
	test("Создание дроби из целого числа", a, Rational(6, 1));
	a = Rational(6, -3);
	test("Отрицательные числа", a, Rational(-2, 1));
	a = Rational(1, 2);
	cout << endl;

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
	cout << endl;

	cout << "---Исключения---" << endl;
	try { a / Rational(0); }
	catch (runtime_error e) { cout << "Нельзя делить на 0!" << endl; }
	cout << endl;
	return 0;
}