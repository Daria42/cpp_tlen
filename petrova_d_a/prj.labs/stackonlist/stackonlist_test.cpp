#include "stackonlist.h"
//#include "stackonlist.cpp"
#include <iostream>
#include <sstream>

int main() {
	using namespace std;
	StackOnList a;
	cout << a.empty() << " ";
	a.push(1);
	cout << a.empty() << " ";
	a.pop();
	cout << a.empty() << endl;
	a.push(2);
	a.push(3);
	a.pop();
	a.push(4);
	cout << a.top() << " ";
	a.push(5);
	cout << a.top() << " ";
	a.pop();
	a.pop();
	cout << a.top() << endl;
	a.push(1);
	StackOnList b(a);
	b.pop();
	cout << a.top() << " " << b.top() << endl;
	a = b;
	cout << a.top() << " " << b.top() << endl;
	return 0;
}