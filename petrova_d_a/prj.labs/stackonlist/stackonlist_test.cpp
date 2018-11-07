#include "stackonlist.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	StackOnList a;
	cout << "������ ������ a" << endl;
	cout << "a.empty() ����������: " << a.empty() << endl;
	a.push(1);
	cout << "���������� �������� { 1 } � a" << endl;
	cout << "a.empty() ����������: " << a.empty() << endl;
	cout << "a.top() ����������: " << a.top() << endl;
	a.pop();
	cout << "�������� �������� �� a (a.pop())" << endl;
	try { a.pop(); }
	catch (runtime_error ex) { cout << "��� ������� ������� ������� �� ������� ����� ������������� ����������" << endl; }
	cout << "���������� ���� ��������� � a" << endl;
	a.push(1);
	a.push(2);
	StackOnList b = a;
	b.push(3);
	cout << "�������� ����� ����� a � ���������� � ���� ��� ������ ��������" << endl;
	cout << "a.top() ����������: " << a.top() << endl;
	cout << "b.top() ����������: " << b.top() << endl;
	return 0;
}