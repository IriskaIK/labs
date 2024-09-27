#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <vector>

template <typename T>
class ArrayQueue {
private:
    std::vector<T> items;

public:
    void enqueue(const T& element);
    T dequeue();
    T front() const;
    bool isEmpty() const;
};

#include "array_queue.cpp" // Including implementation for templates

#endif
