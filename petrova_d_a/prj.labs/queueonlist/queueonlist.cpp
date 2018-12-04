#include <iostream>
#include "queueonlist.h"

QueueOnList::QueueOnList(const QueueOnList &arr) {
    begin_ = nullptr;
    if (arr.empty()) return;
    begin_ = new Node(nullptr, arr.begin_->data_);
    end_ = begin_;
    Node* data = arr.begin_;
    while (data != arr.end_) {
        data = data->next_;
        end_->next_ = new Node(end_, data->data_);
        end_->next_->prev_ = end_;
        end_ = end_->next_;
    }
}

QueueOnList::~QueueOnList() {
    while (!empty()) pop();
}

void QueueOnList::push(const int val) {
    if (empty()) {
        end_ = new Node(nullptr, val);
        begin_ = end_;
    } else {
        end_->next_ = new Node(end_, val);
        end_->next_->prev_ = end_;
        end_ = end_->next_;
    }
}

int& QueueOnList::top() {
    if (empty()) {
        throw std::runtime_error("empty!");
    }
    return begin_->data_;
}

void QueueOnList::pop() {
    if (empty()) {
        throw std::runtime_error("empty!");
    }
    Node *old = begin_;
    begin_ = begin_->next_;
    delete old;
}

QueueOnList& QueueOnList::operator=(const QueueOnList &arr) {
    if (&arr == this) {
        return *this;
    }
    QueueOnList temp(arr);
    Node* tmp = temp.end_;
    temp.end_ = end_;
    end_ = tmp;
    return (*this);
}
