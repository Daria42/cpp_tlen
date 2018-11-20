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

    cout << "---Работа с матрицами---";
    Matrix A(2, 2);
    cout << endl << "По умолчанию (Матрица A):";
    mout(A);
    A.get(0, 0) = 1;
    cout << endl << "Изменение элемента (1, 1) на 1:";
    mout(A);
    Matrix B = A;
    cout << endl << "Оператор присваивания (Матрица B):";
    mout(B);
    B.get(0, 0) += 10;
    cout << endl << "Прибавление к элементу (1, 1) матрицы B 10:";
    mout(B);
    cout << endl << "Матрица A:";
    mout(A);
    cout << endl;

    cout << "---Исключения---" << endl;
    try {
        Matrix d(-1, 12);
    }
    catch (invalid_argument ex) {
        cout << "Матрица с отрицатеьным размером не создаётся" << endl;
    }
    try { A.get(10, 100); }
    catch (out_of_range ex) {
        cout << "Нельзя получить элемент матрицы по выходящим за границы индексам" << endl;
    }
    return 0;
}
