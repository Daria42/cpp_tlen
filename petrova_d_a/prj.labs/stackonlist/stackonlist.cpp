#include "stackonlist.h"

template <typename T>
StackOnList<T>::StackOnList(const StackOnList &arr) {
	capacity_ = arr.capacity_;
	data_ = new T[capacity_];
	for (int i = 0; i < arr.size(); i++)
		data_[i] = arr.data_[i];
}

template <typename T>
void StackOnList<T>::push(const )