#ifndef PETROVA_D_A_PRJ_LABS_QUEUEONARRAY_QUEUEONARRAY_H_
#define PETROVA_D_A_PRJ_LABS_QUEUEONARRAY_QUEUEONARRAY_H_
#include <iosfwd>

class QueueOnArray {
 public:
    QueueOnArray() = default;
    QueueOnArray(const QueueOnArray &arr);
    ~QueueOnArray() { delete[] data_; data_ = nullptr; }
    void push(const int val);
    void pop();
    int& top();
    bool empty() const { return last_ < first_; }
    QueueOnArray& operator=(const QueueOnArray &arr);

 private:
    ptrdiff_t last_{ -1 };
    ptrdiff_t first_{ 0 };
    ptrdiff_t capacity_{ 0 };
    int* data_{ nullptr };
};

#endif  // PETROVA_D_A_PRJ_LABS_QUEUEONARRAY_QUEUEONARRAY_H_
