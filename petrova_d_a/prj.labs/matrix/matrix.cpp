#include "matrix.h"
#include <iostream>
#include <algorithm>
#include <sstream>

Matrix::Matrix(const ptrdiff_t row, const ptrdiff_t col) {
	if (row <= 0 || col <= 0) throw "Not Matrix!";
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
	resize(mat.row_, mat.col_);
	for (int i = 0; i < row_; i++)
		for (int j = 0; j < col_; j++)
			data_[i][j] = mat.data_[i][j];
	return (*this);
}

int& Matrix::get(const ptrdiff_t i, const ptrdiff_t j) {
	if (i >= row_ || i < 0 || j >= col_ || j < 0)
		throw "Out of range!";
	return data_[i][j];
}