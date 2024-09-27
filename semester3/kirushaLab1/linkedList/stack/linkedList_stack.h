#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

template <typename T>
class StackNode {
public:
    T value;
    StackNode* next;

    StackNode(const T& value) : value(value), next(nullptr) {}
};

template <typename T>
class LinkedListStack {
private:
    StackNode<T>* head;

public:
    LinkedListStack();
    ~LinkedListStack();

    void push(const T& element);
    T pop();
    T peek() const;
    bool isEmpty() const;
};

#include "linkedList_stack.cpp" // Including implementation for templates

#endif
