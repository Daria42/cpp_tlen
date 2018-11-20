#include "queueonarray.h"
#include <iostream>
#include <utility>

QueueOnArray::QueueOnArray(const QueueOnArray &arr) {
    last_ = arr.last_;
    first_ = arr.first_;
    capacity_ = arr.capacity_;
    data_ = new int[capacity_];
    for (int i = first_; i <= last_; i++) {
        data_[i % capacity_] = arr.data_[i % capacity_];
    }
}

void QueueOnArray::push(const int val) {
    if (last_ - first_ + 1 >= capacity_) {
        ptrdiff_t capacity = capacity_ * 2;
        if (capacity == 0) {
            capacity++;
        }
        int *data = new int[capacity];
        for (int i = first_; i <= last_; i++) {
            data[i - first_] = data_[i % capacity_];
        }
        std::swap(data, data_);
        std::swap(capacity, capacity_);
        last_ -= first_;
        first_ = 0;
    }
    last_++;
    data_[last_ % capacity_] = val;
}

int& QueueOnArray::top() {
    if (empty()) {
        throw std::runtime_error("empty!");
    }
    return data_[first_ % capacity_];
}

void QueueOnArray::pop() {
    if (empty()) {
        throw std::runtime_error("empty!");
    }
    first_++;
}

QueueOnArray& QueueOnArray::operator=(const QueueOnArray &arr) {
    if (&arr == this) {
        return *this;
    }
    QueueOnArray temp(arr);
    std::swap(temp.capacity_, capacity_);
    std::swap(temp.data_, data_);
    std::swap(temp.first_, first_);
    std::swap(temp.last_, last_);
    return (*this);
}
