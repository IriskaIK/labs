#include "linkedList_queue.h"
#include <stdexcept>

template <typename T>
LinkedListQueue<T>::LinkedListQueue() : frontNode(nullptr), rearNode(nullptr) {}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void LinkedListQueue<T>::enqueue(const T& element) {
    QueueNode<T>* newNode = new QueueNode<T>(element);
    if (rearNode) {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    if (!frontNode) {
        frontNode = rearNode;
    }
}

template <typename T>
T LinkedListQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    QueueNode<T>* temp = frontNode;
    T value = temp->value;
    frontNode = frontNode->next;
    if (!frontNode) {
        rearNode = nullptr;
    }
    delete temp;
    return value;
}

template <typename T>
T LinkedListQueue<T>::front() const {
    if (!frontNode) {
        throw std::out_of_range("Queue is empty");
    }
    return frontNode->value;
}

template <typename T>
bool LinkedListQueue<T>::isEmpty() const {
    return frontNode == nullptr;
}
