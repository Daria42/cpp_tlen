#ifndef PETROVA_D_A_PRJ_LABS_STACKONARRAY_STACKONARRAY_H_
#define PETROVA_D_A_PRJ_LABS_STACKONARRAY_STACKONARRAY_H_
#include <iosfwd>

class StackOnArray {
 public:
    StackOnArray() = default;
    StackOnArray(const StackOnArray &arr);
    ~StackOnArray() { delete[] data_; data_ = nullptr; }
    void push(const int val);
    void pop();
    int& top();
    bool empty() const { return head_ == -1; }
    StackOnArray& operator=(const StackOnArray &arr);

 private:
    ptrdiff_t head_{ -1 };
    ptrdiff_t capacity_{ 0 };
    int* data_{ nullptr };
};

#endif  // PETROVA_D_A_PRJ_LABS_STACKONARRAY_STACKONARRAY_H_
