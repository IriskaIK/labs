#ifndef ARRAY_DEQUE_H
#define ARRAY_DEQUE_H

#include <vector>

template <typename T>
class ArrayDeque {
private:
    std::vector<T> items;

public:
    void pushFront(const T& element);
    void pushBack(const T& element);
    T popFront();
    T popBack();
    T front() const;
    T back() const;
    bool isEmpty() const;
};

#include "array_deque.cpp" // Including implementation for templates

#endif
