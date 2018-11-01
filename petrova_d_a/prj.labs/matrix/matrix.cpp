#include "matrix.h"
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

Matrix::Matrix(const ptrdiff_t row, const ptrdiff_t col) {
	if (row <= 0 || col <= 0) throw invalid_argument("Not Matrix!");
	row_ = row;
	col_ = col;
	rowcap_ = row * 3 / 2;
	colcap_ = col * 3 / 2;
	data_ = new int*[rowcap_];
	for (int i = 0; i < rowcap_; i++) {
		data_[i] = new int[colcap_];
		for (int j = 0; j < colcap_; j++)
			data_[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix &mat) {
	row_ = mat.row_;
	col_ = mat.col_;
	rowcap_ = mat.rowcap_;
	colcap_ = mat.colcap_;
	data_ = new int*[rowcap_];
	for (int i = 0; i < rowcap_; i++) {
		data_[i] = new int[colcap_];
		for (int j = 0; j < colcap_; j++)
			data_[i][j] = mat.data_[i][j];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < rowcap_; i++)
		delete[] data_[i];
	delete[] data_;
}

void Matrix::resize(const ptrdiff_t row, const ptrdiff_t col) {
	if (row > rowcap_ || col > colcap_) {
		rowcap_ = row * 3 / 2;
		colcap_ = col * 3 / 2;
		int **data = new int*[rowcap_];
		for (int i = 0; i < rowcap_; i++) {
			data[i] = new int[colcap_];
			for (int j = 0; j < colcap_; j++) {
				if (i < row_ && j < col_) data[i][j] = data_[i][j];
				else data[i][j] = 0;
			}
		}
		data_ = data;
	}
	row_ = row;
	col_ = col;
}

Matrix& Matrix::operator=(const Matrix& mat) {
	if (&mat == this) return *this;
	Matrix temp = Matrix(mat);
	swap(temp.colcap_, colcap_);
	swap(temp.col_, col_);
	swap(temp.rowcap_, rowcap_);
	swap(temp.row_, row_);
	swap(temp.data_, data_);
	resize(mat.row_, mat.col_);
	return (*this);
}

int& Matrix::get(const ptrdiff_t i, const ptrdiff_t j) {
	if (i >= row_ || i < 0 || j >= col_ || j < 0)
		throw out_of_range("Out of range!");
	return data_[i][j];
}