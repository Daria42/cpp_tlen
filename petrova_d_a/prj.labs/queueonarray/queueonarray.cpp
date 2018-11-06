#include <iostream>
#include "queueonarray.h"

using namespace std;

QueueOnArray::QueueOnArray(const QueueOnArray &arr) {
	last_ = arr.last_;
	first_ = arr.first_;
	capacity_ = arr.capacity_;
	data_ = new int[capacity_];
	for (int i = first_; i <= last_; i++)
		data_[i % capacity_] = arr.data_[i % capacity_];
}

void QueueOnArray::push(const int val) {
	if (capacity_ == 0 || last_ % capacity_ == first_ % capacity_) {
		ptrdiff_t capacity = capacity_ * 2;
		if (capacity == 0) capacity++;
		int* data = new int[capacity];
		for (int i = first_; i <= last_; i++)
			data[i - first_] = data_[i % capacity];
		swap(data, data_);
		capacity_ = capacity;
		last_ -= first_;
		first_ = 0;
	}
	last_++;
	data_[last_ % capacity_] = val;
}

int& QueueOnArray::top() {
	if (empty()) throw runtime_error("empty!");
	return data_[first_ % capacity_];
}

void QueueOnArray::pop() {
	if (empty()) throw runtime_error("empty!");
	first_++;
}

QueueOnArray& QueueOnArray::operator=(const QueueOnArray &arr) {
	if (&arr == this) return *this;
	QueueOnArray temp(arr);
	swap(temp.capacity_, capacity_);
	swap(temp.data_, data_);
	swap(temp.first_, first_);
	swap(temp.last_, last_);
	return (*this);
}