#include "queueonarray.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    QueueOnArray a;
    cout << "������ ������� a" << endl;
    cout << "a.empty() ����������: " << a.empty() << endl;
    a.push(1);
    cout << "���������� �������� { 1 } � a" << endl;
    cout << "a.empty() ����������: " << a.empty() << endl;
    cout << "a.top() ����������: " << a.top() << endl;
    a.pop();
    cout << "�������� �������� �� a (a.pop())" << endl;
    try {
        a.pop();
    }
    catch (runtime_error ex) {
        cout << "��� ������� ������� ������� �� ������ ������� ������������� ����������" << endl;
    }
    cout << "���������� ������ ��������� � a" << endl;
    for (int i = 1; i <= 10; i++) {
        a.push(i);
    }
    QueueOnArray b = a;
    b.pop();
    cout << "�������� ����� ����� a � �������� �� ���� ������ ��������" << endl;
    cout << "��� �������� ������� a: ";
    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl << "��� �������� ������� b: ";
    while (!b.empty()) {
        cout << b.top() << " ";
        b.pop();
    }
    return 0;
}
