#include "dynamicarray.h"

template <typename T>
DynamicArray<T>::DynamicArray(const ptrdiff_t size): size_(size) {
	if (size < 0) throw "size < 0 !";
	capacity_ = size * 3/2;
	if (capacity_ > 0) data_ = new int[capacity_];
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
	(*this).resize(arr.size_);
	for (int i = 0; i < arr.size(); i++)
		(*this).data_[i] = arr.data_[i];
	return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](const ptrdiff_t index) {
	if (index >= (*this).size() || index < 0) throw "Index is out of range!";
	return *(data_ + index);
}

//const int& DynamicArray::operator[](const ptrdiff_t index) const {
//	if (index >= (*this).size() || index < 0) throw "Index is out of range!";
//	return *(data_ + index);
//}

template <typename T>
void DynamicArray<T>::resize(const ptrdiff_t size) {
	if (size < 0) throw "size < 0 !";
	if (size <= capacity_) size_ = size;
	else {
		capacity_ = size * 3 / 2;
		int *data = new T[capacity_];
		for (int i = 0; i < size_; i++)
			data[i] = data_[i];
		size_ = size;
		data_ = data;
	}
}