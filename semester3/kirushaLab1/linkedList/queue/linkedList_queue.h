#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

template <typename T>
class QueueNode {
public:
    T value;
    QueueNode* next;

    QueueNode(const T& value) : value(value), next(nullptr) {}
};

template <typename T>
class LinkedListQueue {
private:
    QueueNode<T>* frontNode;
    QueueNode<T>* rearNode;

public:
    LinkedListQueue();
    ~LinkedListQueue();

    void enqueue(const T& element);
    T dequeue();
    T front() const;
    bool isEmpty() const;
};

#include "linkedList_queue.cpp" // Including implementation for templates

#endif
