#include "queueonarray.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    QueueOnArray a;
    cout << "Пустая очередь a" << endl;
    cout << "a.empty() возвращает: " << a.empty() << endl;
    a.push(1);
    cout << "Добавление элемента { 1 } в a" << endl;
    cout << "a.empty() возвращает: " << a.empty() << endl;
    cout << "a.top() возвращает: " << a.top() << endl;
    a.pop();
    cout << "Удаление элемента из a (a.pop())" << endl;
    try {
        a.pop();
    }
    catch (runtime_error ex) {
        cout << "При попытке удалить элемент из пустой очереди выбрасывается исключение" << endl;
    }
    cout << "Добавление десяти элементов в a" << endl;
    for (int i = 1; i <= 10; i++) {
        a.push(i);
    }
    QueueOnArray b = a;
    b.pop();
    cout << "Создание копии стэка a и удаление из него одного элемента" << endl;
    cout << "Все элементы очереди a: ";
    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl << "Все элементы очереди b: ";
    while (!b.empty()) {
        cout << b.top() << " ";
        b.pop();
    }
    return 0;
}
