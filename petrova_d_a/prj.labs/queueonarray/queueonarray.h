#ifndef queueonarray_h
#define queueonarray_h

#include <iosfwd>

class QueueOnArray {
public:
	QueueOnArray() = default;
	QueueOnArray(const QueueOnArray &arr);
	~QueueOnArray() { delete[] data_; data_ = nullptr; }
	void push(const int val);
	void pop();
	int& top();
	bool empty() const { return last_ < first_; };
	QueueOnArray& operator=(const QueueOnArray &arr);
private:
	ptrdiff_t last_{ -1 };
	ptrdiff_t first_{ 0 };
	ptrdiff_t capacity_{ 0 };
	int* data_{ nullptr };
};

#endif