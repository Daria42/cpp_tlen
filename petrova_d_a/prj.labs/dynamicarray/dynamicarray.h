#ifndef PETROVA_D_A_PRJ_LABS_DYNAMICARRAY_DYNAMICARRAY_H_
#define PETROVA_D_A_PRJ_LABS_DYNAMICARRAY_DYNAMICARRAY_H_
#include <iosfwd>

template <typename T>
class DynamicArray {
 public:
    DynamicArray() = default;
    explicit DynamicArray(const ptrdiff_t size);
    DynamicArray(const ptrdiff_t size, const T &val);
    DynamicArray(const DynamicArray &arr);
    ~DynamicArray() { delete[] data_; data_ = nullptr; }
    ptrdiff_t size() const { return size_; }
    T& operator[](const ptrdiff_t index);
    T& operator[](const ptrdiff_t index) const;
    void resize(const ptrdiff_t size);
    void resize(const ptrdiff_t size, const T &val);
    const DynamicArray &operator=(const DynamicArray<T> &arr);

 private:
    ptrdiff_t size_{ 0 };
    ptrdiff_t capacity_{ 0 };
    T* data_{ nullptr };
};


template <typename T>
DynamicArray<T>::DynamicArray(const ptrdiff_t size) : size_(size) {
    if (size < 0) {
        throw invalid_argument("size < 0 !");
    }
    capacity_ = size_;
    if (capacity_ > 0) {
        data_ = new T[capacity_];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const ptrdiff_t size, const T &val)
    : DynamicArray(size) {
    for (int i = 0; i < size_; i++) {
        *(data_ + i) = val;
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &arr)
    : DynamicArray(arr.size_) {
    for (int i = 0; i < arr.size(); i++) {
        data_[i] = arr.data_[i];
    }
}

template <typename T>
const DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &arr) {
    if (this != &arr) {
        DynamicArray<T> temp(arr);
        std::swap(size_, temp.size_);
        std::swap(capacity_, temp.capacity_);
        std::swap(data_, temp.data_);
    }
    return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](const ptrdiff_t index) {
    if (index >= (*this).size() || index < 0) {
        throw out_of_range("Index is out of range!");
    }
    return *(data_ + index);
}

template <typename T>
T& DynamicArray<T>::operator[](const ptrdiff_t index) const {
    if (index >= (*this).size() || index < 0) {
        throw out_of_range("Index is out of range!");
    }
    return *(data_ + index);
}

template <typename T>
void DynamicArray<T>::resize(const ptrdiff_t size) {
    if (size < 0) {
        throw invalid_argument("Size < 0!");
    }
    if (size <= capacity_) {
        size_ = size;
    }
    else {
        capacity_ = size * 2;
        T *data = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            data[i] = data_[i];
        }
        data_ = data;
        size_ = size;
    }
}

template <typename T>
void DynamicArray<T>::resize(const ptrdiff_t size, const T& val) {
    resize(size);
    for (int i = 0; i < size_; i++) {
        data_[i] = val;
    }
}


#endif  // PETROVA_D_A_PRJ_LABS_DYNAMICARRAY_DYNAMICARRAY_H_
