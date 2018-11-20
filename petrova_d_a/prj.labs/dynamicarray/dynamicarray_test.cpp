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
    cout << "---������ � ���������---" << endl;
    cout << endl << "�������� �� ���������";
    aout(a);
    a = DynamicArray<int>(5);
    cout << endl << "������ � �������� ��������";
    aout(a);
    a = DynamicArray<int>(5, 2);
    cout << endl << "������ � �������� �������� � �������������� ��������� ���������";
    aout(a);
    DynamicArray<int> b = a;
    cout << endl << "����������� � ����� ������";
    aout(a);
    b[2] = 5;
    cout << endl << "��������� �������� ������� �������";
    aout(b);
    cout << endl << "������ ������";
    aout(a);
    a.resize(10);
    cout << endl << "���������� ������� ������� �������";
    aout(a);
    a.resize(2, -1);
    cout << endl << "���������� ������� ������� ������� � ���������� ���� ���������";
    aout(a);
    cout << endl;

    cout << "---����������---" << endl;
    try {
        DynamicArray<int> d(-1);
    }
    catch(invalid_argument ex) {
        cout << "������ ������� ������ ������������� �����" << endl;
    }
    try {
        a[1000];
    }
    catch (out_of_range ex) {
        cout << "������ ���������� �� �������, ������������ ����� �������" << endl;
    }
    try {
        a[-1];
    }
    catch (out_of_range ex) {
        cout << "������ ���������� �� �������������� �������" << endl;
    }
    return 0;
}
