#ifndef rational_h
#define rational_h

#include <iosfwd>

class DynamicArray {
public:
	DynamicArray() = default;
	DynamicArray(const int size);
	DynamicArray(const DynamicArray &arr);
	~DynamicArray() { delete data_; };
	ptrdiff_t size() const { return size_; }
	int& operator[](const ptrdiff_t index) { return data_[index]; }
	void resize(const int size);
	DynamicArray& operator=(const DynamicArray arr);
private:
	ptrdiff_t size_{ 0 };
	ptrdiff_t capacity_{ 0 };
	int* data_{ nullptr };
};

#endif