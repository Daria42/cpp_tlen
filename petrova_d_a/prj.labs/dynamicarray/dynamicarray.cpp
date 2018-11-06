#include "dynamicarray.h"

using namespace std;

template <typename T>
DynamicArray<T>::DynamicArray(const ptrdiff_t size): size_(size) {
	if (size < 0) throw invalid_argument("size < 0 !");
	capacity_ = size * 2;
	if (capacity_ > 0) data_ = new T[capacity_];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &arr) {
	size_ = arr.size_;
	capacity_ = arr.capacity_;
	data_ = new T[capacity_];
	for (int i = 0; i < arr.size(); i++)
		data_[i] = arr.data_[i];
}

template <typename T>
const DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &arr) {
	if (this == &arr) return *this;
	DynamicArray<T> temp(arr);
	std::swap(size_, temp.size_);
	std::swap(capacity_, temp.capacity_);
	std::swap(data_, temp.data_);
	return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](const ptrdiff_t index) {
	if (index >= (*this).size() || index < 0) throw out_of_range("Index is out of range!");
	return *(data_ + index);
}

template <typename T>
const T& DynamicArray<T>::operator[](const ptrdiff_t index) const {
	if (index >= (*this).size() || index < 0) throw out_of_range("Index is out of range!");
	return *(data_ + index);
}

template <typename T>
void DynamicArray<T>::resize(const ptrdiff_t size) {
	if (size < 0) throw invalid_argument("Size < 0!");
	if (size <= capacity_) size_ = size;
	else {
		if (capacity_ == 0) capacity_ = 1;
		else capacity_ = size * 2;
		T *data = new T[capacity_];
		for (int i = 0; i < size_; i++)
			data[i] = data_[i];
		data_ = data;
		size_ = size;
	}
}