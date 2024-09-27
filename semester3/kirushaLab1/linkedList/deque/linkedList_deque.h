#ifndef LINKEDLIST_DEQUE_H
#define LINKEDLIST_DEQUE_H

template <typename T>
class DequeNode {
public:
    T value;
    DequeNode* next;
    DequeNode* prev;

    DequeNode(const T& value) : value(value), next(nullptr), prev(nullptr) {}  // Initialize both next and prev
};
template <typename T>
class LinkedListDeque {
private:
    DequeNode<T>* frontNode;
    DequeNode<T>* rearNode;

public:
    LinkedListDeque();
    ~LinkedListDeque();

    void pushFront(const T& element);
    void pushBack(const T& element);
    T popFront();
    T popBack();
    T front() const;
    T back() const;
    bool isEmpty() const;
};

#include "linkedList_deque.cpp" // Including implementation for templates

#endif
