#include "dynamicarray.h"
#include "dynamicarray.cpp"
#include <iostream>
#include <sstream>

int main() {
	using namespace std;
	DynamicArray<int> a;
	DynamicArray<int> b(5);
	b[0] = 1; b[2] = 2; b[3] = 3; b[1] = 0; b[4] = 4;
	DynamicArray<int> c(b);
	cout << "a: ";
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << endl;
	cout << "b: ";
	for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
	cout << endl;
	cout << "c: ";
	for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
	b.resize(2);
	b[0] = 10;
	b.resize(10);
	b[6] = 1; b[7] = 2; b[8] = 3; b[9] = 4;
	cout << endl;
	cout << "b: ";
	for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
	cout << endl;
	a = b;
	cout << "b: ";
	for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
	cout << endl;
	cout << "a: ";
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}