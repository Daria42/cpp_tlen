#include "stackonlist.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	StackOnList a;
	cout << "Пустой список a" << endl;
	cout << "a.empty() возвращает: " << a.empty() << endl;
	a.push(1);
	cout << "Добавление элемента { 1 } в a" << endl;
	cout << "a.empty() возвращает: " << a.empty() << endl;
	cout << "a.top() возвращает: " << a.top() << endl;
	a.pop();
	cout << "Удаление элемента из a (a.pop())" << endl;
	try { a.pop(); }
	catch (runtime_error ex) { cout << "При попытке удалить элемент из пустого стэка выбрасывается исключение" << endl; }
	cout << "Добавление двух элементов в a" << endl;
	a.push(1);
	a.push(2);
	StackOnList b = a;
	b.push(3);
	cout << "Создание копии стэка a и добавление в него ещё одного элемента" << endl;
	cout << "a.top() возвращает: " << a.top() << endl;
	cout << "b.top() возвращает: " << b.top() << endl;
	return 0;
}