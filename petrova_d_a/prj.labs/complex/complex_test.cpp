#include "complex.h"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
void test(string test, T rhs, T ans) {
    cout << test << ": " << rhs << " ";
    if (rhs == ans) {
        cout << "OK";
    } else {
        cout << "WA: " << ans;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "---Конструктор---" << endl;
    Complex a;
    test("Значение по умолчанию", a, Complex(0.0, 0.0));
    a = Complex(2.0, 8.0);
    test("Создание комплексного числа, оператор = ", a, Complex(2.0, 8.0));
    a = Complex(6.0);
    test("Создание комплексного числа по действительной части",
        a, Complex(6.0, 0.0));
    cout << endl;

    cout << "---Сравнение---" << endl;
    a = Complex(1.0, 1.0);
    Complex b(1.0, 1.0 + 1e-10);
    test("Сравнение чисел с точностью до 7 знака после запятой", (a == b), true);
    cout << endl;
    

    cout << "---Арифметические операции---" << endl;
    a = Complex(1.0, 2.0);
    b = Complex(2.0, 1.0);
    test("Сумма", a + b, Complex(3.0, 3.0));
    test("Разность", a - b, Complex(-1.0, 1.0));
    test("Умножение", a * b, Complex(0.0, 5.0));
    test("Деление", a / b, Complex(0.8, 0.6));
    test("Присваивание суммы", a += b, Complex(3.0, 3.0));
    test("Присваивание разности", a -= b, Complex(1.0, 2.0));
    test("Присваивание произведения", a *= b, Complex(0.0, 5.0));
    test("Присваивание частного", a /= b, Complex(1.0, 2.0));
    cout << endl;

    cout << "---Смешанная арифметика---" << endl;
    double k = 2.0;
    test("Сумма", a + k, Complex(3.0, 2.0));
    test("Разность", a - k, Complex(-1.0, 2.0));
    test("Умножение", a * k, Complex(2.0, 4.0));
    test("Деление", a / k, Complex(0.5, 1.0));
    test("Присваивание суммы", a += k, Complex(3.0, 2.0));
    test("Присваивание разности", a -= k, Complex(1.0, 2.0));
    test("Присваивание произведения", a *= k, Complex(2.0, 4.0));
    test("Присваивание частного", a /= k, Complex(1.0, 2.0));
    cout << endl;

    cout << "---Исключения---" << endl;
    try { a / Complex(0, 0); }
    catch (runtime_error e) { cout << "Нельзя делить на 0!" << endl; }
    cout << endl;
    return 0;
}
