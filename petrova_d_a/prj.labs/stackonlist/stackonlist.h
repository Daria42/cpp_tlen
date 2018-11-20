#ifndef PETROVA_D_A_PRJ_LABS_STACKONLIST_STACKONLIST_H_
#define PETROVA_D_A_PRJ_LABS_STACKONLIST_STACKONLIST_H_
#include <iosfwd>

class StackOnList {
 public:
    StackOnList() = default;
    StackOnList(const StackOnList &arr);
    ~StackOnList();
    void push(const int val);
    void pop();
    int& top();
    bool empty() const { return head_ == nullptr; }
    StackOnList& operator=(const StackOnList &arr);
 private:
    struct Node {
        Node* next_{ nullptr };
        int data_{ 0 };
        Node(Node* next, const int &data) : next_(next), data_(data) { }
    };
    Node* head_{ nullptr };
};

#endif  // PETROVA_D_A_PRJ_LABS_STACKONLIST_STACKONLIST_H_
