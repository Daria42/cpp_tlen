#ifndef dynamicarray_h
#define dynamicarray_h

#include <iosfwd>

template <typename T>
class DynamicArray {
public:
	DynamicArray() = default;
	DynamicArray(const ptrdiff_t size);
	DynamicArray(const DynamicArray &arr);
	~DynamicArray() { delete[] data_; };
	ptrdiff_t size() const { return size_; }
	T& operator[](const ptrdiff_t index);
	//const int& operator[](const ptrdiff_t index) const;
	void resize(const ptrdiff_t size);
	const DynamicArray &operator=(const DynamicArray<T> &arr);
private:
	ptrdiff_t size_{ 0 };
	ptrdiff_t capacity_{ 0 };
	T* data_{ nullptr };
};

#endif