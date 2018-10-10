#include "matrix.h"
#include <iostream>
#include <sstream>

int main() {
	using namespace std;
	Matrix A(2, 2);
	A.get(0, 0) += 1;
	cout << "-- A --" << endl;
	for (int i = 0; i < A.rows(); i++, cout << endl)
		for (int j = 0; j < A.columns(); j++)
			cout << A.get(i, j) << " ";
	cout << endl;
	Matrix B(2, 2);
	A = B;
	B.get(0, 0) += 2;
	cout << "-- A --" << endl;
	for (int i = 0; i < A.rows(); i++, cout << endl)
		for (int j = 0; j < A.columns(); j++)
			cout << A.get(i, j) << " ";
	cout << endl;
	A.resize(5, 3);
	cout << "-- A --" << endl;
	for (int i = 0; i < A.rows(); i++, cout << endl)
		for (int j = 0; j < A.columns(); j++)
			cout << A.get(i, j) << " ";
	cout << endl;
	A.get(3, 2) = 6;
	A.get(3, 1) = 6;
	A.get(3, 0) = 6;
	Matrix C(A);
	cout << "-- C --" << endl;
	for (int i = 0; i < C.rows(); i++, cout << endl)
		for (int j = 0; j < C.columns(); j++)
			cout << C.get(i, j) << " ";
	return 0;
}