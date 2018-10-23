#ifndef stackonlist_h
#define stackonlist_h

#include <iosfwd>

template <typename T>
struct Node {
	Node<T>* next{ nullptr };
	T data;
};

template <typename T>
class StackOnList {
public:
	StackOnList();
	StackOnList(const StackOnList &arr);
	~StackOnList() = default;
	void push(const T val);
	void pop();
	T& top();
	bool empty() { return data_.size() > 0; };
	//const StackOnList &operator=(const StackOnList<T> &arr);
private:
	Node<T>* head_{ nullptr };
};

#endif