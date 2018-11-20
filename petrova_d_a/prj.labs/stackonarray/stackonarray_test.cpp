#include "stackonarray.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    StackOnArray a;
    cout << "������ ������ a" << endl;
    cout << "a.empty() ����������: " << a.empty() << endl;
    a.push(1);
    cout << "���������� �������� { 1 } � a" << endl;
    cout << "a.empty() ����������: " << a.empty() << endl;
    cout << "a.top() ����������: " << a.top() << endl;
    a.pop();
    cout << "�������� �������� �� a (a.pop())" << endl;
    try {
        a.pop();
    } catch (runtime_error ex) {
        cout << "��� ������� ������� ������� �� ������� ����� ������������� ����������" << endl;
    }
    cout << "���������� ������ ��������� � a" << endl;
    for (int i = 1; i <= 10; i++) a.push(i);
    StackOnArray b = a;
    b.push(11);
    cout << "�������� ����� ����� a � ���������� � ���� ��� ������ ��������" << endl;
    cout << "a.top() ����������: " << a.top() << endl;
    cout << "b.top() ����������: " << b.top() << endl;
    return 0;
}
