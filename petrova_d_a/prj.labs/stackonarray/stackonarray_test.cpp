#include "stackonarray.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    StackOnArray a;
    cout << "Пустой список a" << endl;
    cout << "a.empty() возвращает: " << a.empty() << endl;
    a.push(1);
    cout << "Добавление элемента { 1 } в a" << endl;
    cout << "a.empty() возвращает: " << a.empty() << endl;
    cout << "a.top() возвращает: " << a.top() << endl;
    a.pop();
    cout << "Удаление элемента из a (a.pop())" << endl;
    try {
        a.pop();
    } catch (runtime_error ex) {
        cout << "При попытке удалить элемент из пустого стэка выбрасывается исключение" << endl;
    }
    cout << "Добавление десяти элементов в a" << endl;
    for (int i = 1; i <= 10; i++) a.push(i);
    StackOnArray b = a;
    b.push(11);
    cout << "Создание копии стэка a и добавление в него ещё одного элемента" << endl;
    cout << "a.top() возвращает: " << a.top() << endl;
    cout << "b.top() возвращает: " << b.top() << endl;
    return 0;
}
