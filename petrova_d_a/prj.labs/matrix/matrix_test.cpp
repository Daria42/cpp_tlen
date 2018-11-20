#include "matrix.h"
#include <iostream>
#include <sstream>

using namespace std;

void mout(const Matrix &m) {
    cout << endl;
    for (int i = 0; i < m.rows(); i++, cout << endl) {
        for (int j = 0; j < m.columns(); j++) {
            cout << m.get(i, j) << " ";
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "---������ � ���������---";
    Matrix A(2, 2);
    cout << endl << "�� ��������� (������� A):";
    mout(A);
    A.get(0, 0) = 1;
    cout << endl << "��������� �������� (1, 1) �� 1:";
    mout(A);
    Matrix B = A;
    cout << endl << "�������� ������������ (������� B):";
    mout(B);
    B.get(0, 0) += 10;
    cout << endl << "����������� � �������� (1, 1) ������� B 10:";
    mout(B);
    cout << endl << "������� A:";
    mout(A);
    cout << endl;

    cout << "---����������---" << endl;
    try {
        Matrix d(-1, 12);
    }
    catch (invalid_argument ex) {
        cout << "������� � ������������ �������� �� ��������" << endl;
    }
    try { A.get(10, 100); }
    catch (out_of_range ex) {
        cout << "������ �������� ������� ������� �� ��������� �� ������� ��������" << endl;
    }
    return 0;
}
