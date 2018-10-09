#include "dynamicarray.h"

DynamicArray::DynamicArray(const int size): size_(size) {
	capacity_ = size * 1.5;
	data_ = new int(capacity_);
}

DynamicArray::DynamicArray(const DynamicArray &arr) {
	size_ = arr.size_;
	capacity_ = arr.capacity_;
	data_ = arr.data_;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &arr) {
	(*this).data_ = arr.data_;
	(*this).capacity_ = arr.capacity_;
	(*this).size_ = arr.size_;
	return *this;
}