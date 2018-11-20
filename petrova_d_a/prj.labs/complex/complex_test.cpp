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

    cout << "---�����������---" << endl;
    Complex a;
    test("�������� �� ���������", a, Complex(0.0, 0.0));
    a = Complex(2.0, 8.0);
    test("�������� ������������ �����, �������� = ", a, Complex(2.0, 8.0));
    a = Complex(6.0);
    test("�������� ������������ ����� �� �������������� �����",
        a, Complex(6.0, 0.0));
    cout << endl;

    cout << "---���������---" << endl;
    a = Complex(1.0, 1.0);
    Complex b(1.0, 1.0 + 1e-10);
    test("��������� ����� � ��������� �� 7 ����� ����� �������", (a == b), true);
    cout << endl;
    

    cout << "---�������������� ��������---" << endl;
    a = Complex(1.0, 2.0);
    b = Complex(2.0, 1.0);
    test("�����", a + b, Complex(3.0, 3.0));
    test("��������", a - b, Complex(-1.0, 1.0));
    test("���������", a * b, Complex(0.0, 5.0));
    test("�������", a / b, Complex(0.8, 0.6));
    test("������������ �����", a += b, Complex(3.0, 3.0));
    test("������������ ��������", a -= b, Complex(1.0, 2.0));
    test("������������ ������������", a *= b, Complex(0.0, 5.0));
    test("������������ ��������", a /= b, Complex(1.0, 2.0));
    cout << endl;

    cout << "---��������� ����������---" << endl;
    double k = 2.0;
    test("�����", a + k, Complex(3.0, 2.0));
    test("��������", a - k, Complex(-1.0, 2.0));
    test("���������", a * k, Complex(2.0, 4.0));
    test("�������", a / k, Complex(0.5, 1.0));
    test("������������ �����", a += k, Complex(3.0, 2.0));
    test("������������ ��������", a -= k, Complex(1.0, 2.0));
    test("������������ ������������", a *= k, Complex(2.0, 4.0));
    test("������������ ��������", a /= k, Complex(1.0, 2.0));
    cout << endl;

    cout << "---����������---" << endl;
    try { a / Complex(0, 0); }
    catch (runtime_error e) { cout << "������ ������ �� 0!" << endl; }
    cout << endl;
    return 0;
}
