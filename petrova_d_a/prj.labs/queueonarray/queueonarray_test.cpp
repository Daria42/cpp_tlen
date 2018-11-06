#include "queueonarray.h"
#include <iostream>
#include <sstream>

int main() {
	using namespace std;
	QueueOnArray a;
	cout << a.empty() << " ";
	a.push(1);
	cout << a.empty() << " ";
	a.pop();
	cout << a.empty() << endl;
	a.push(2);
	a.push(3);
	a.push(4);
	cout << a.top() << " ";
	a.push(5);
	cout << a.top() << " ";
	a.pop();
	cout << a.top() << endl;
	a.pop();
	a.push(1);
	QueueOnArray b(a);
	b.pop();
	cout << a.top() << " " << b.top() << endl; //4, 5
	a = b;
	cout << a.top() << " " << b.top() << endl;
	a.pop();
	a.pop();
	try {
		a.pop();
	}
	catch (runtime_error ex) {
		cout << "Can't pop!" << endl;
	}
	return 0;
}