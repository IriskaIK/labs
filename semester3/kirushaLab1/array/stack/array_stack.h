#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <vector>

template <typename T>
class ArrayStack {
private:
    std::vector<T> items;

public:
    void push(const T& element);
    T pop();
    T peek() const;
    bool isEmpty() const;
};

#include "array_stack.cpp" // Including implementation for templates

#endif