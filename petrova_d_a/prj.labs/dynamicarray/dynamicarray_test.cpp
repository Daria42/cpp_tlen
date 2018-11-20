#include "dynamicarray.h"
#include "dynamicarray.cpp"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
void aout(const DynamicArray<T> &a) {
    cout << endl;
    cout << "size: " << a.size() << endl;
    cout << "elements: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    DynamicArray<int> a;
    cout << "---Работа с массивами---" << endl;
    cout << endl << "Значение по умолчанию";
    aout(a);
    a = DynamicArray<int>(5);
    cout << endl << "Массив с заданным размером";
    aout(a);
    a = DynamicArray<int>(5, 2);
    cout << endl << "Массив с заданным размером и первоначальным значением элементов";
    aout(a);
    DynamicArray<int> b = a;
    cout << endl << "Копирование в новый массив";
    aout(a);
    b[2] = 5;
    cout << endl << "Изменение значения второго элемнта";
    aout(b);
    cout << endl << "Первый массив";
    aout(a);
    a.resize(10);
    cout << endl << "Увеличение размера первого массива";
    aout(a);
    a.resize(2, -1);
    cout << endl << "Уменьшение размера первого массива с изменением всех элементов";
    aout(a);
    cout << endl;

    cout << "---Исключения---" << endl;
    try {
        DynamicArray<int> d(-1);
    }
    catch(invalid_argument ex) {
        cout << "Нельзя создать массив отрицательной длины" << endl;
    }
    try {
        a[1000];
    }
    catch (out_of_range ex) {
        cout << "Нельзя обратиться по индексу, превышающему длину массива" << endl;
    }
    try {
        a[-1];
    }
    catch (out_of_range ex) {
        cout << "Нельзя обратиться по отрицательному индексу" << endl;
    }
    return 0;
}
