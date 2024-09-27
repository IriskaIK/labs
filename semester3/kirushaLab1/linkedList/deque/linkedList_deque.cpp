#include "linkedList_deque.h"
#include <stdexcept>

template <typename T>
LinkedListDeque<T>::LinkedListDeque() : frontNode(nullptr), rearNode(nullptr) {}

template <typename T>
LinkedListDeque<T>::~LinkedListDeque() {
    while (!isEmpty()) {
        popFront();
    }
}

template <typename T>
void LinkedListDeque<T>::pushFront(const T& element) {
    DequeNode<T>* newNode = new DequeNode<T>(element);
    if (frontNode) {
        newNode->next = frontNode;
        frontNode->prev = newNode;
    }
    frontNode = newNode;
    if (!rearNode) {
        rearNode = frontNode;
    }
}

template <typename T>
void LinkedListDeque<T>::pushBack(const T& element) {
    DequeNode<T>* newNode = new DequeNode<T>(element);
    if (rearNode) {
        newNode->prev = rearNode;
        rearNode->next = newNode;
    }
    rearNode = newNode;
    if (!frontNode) {
        frontNode = rearNode;
    }
}

template <typename T>
T LinkedListDeque<T>::popFront() {
    if (!frontNode) {
        throw std::out_of_range("Deque is empty");
    }
    DequeNode<T>* temp = frontNode;
    T value = temp->value;
    frontNode = frontNode->next;
    if (frontNode) {
        frontNode->prev = nullptr;
    } else {
        rearNode = nullptr;
    }
    delete temp;
    return value;
}

template <typename T>
T LinkedListDeque<T>::popBack() {
    if (!rearNode) {
        throw std::out_of_range("Deque is empty");
    }
    DequeNode<T>* temp = rearNode;
    T value = temp->value;
    rearNode = rearNode->prev;
    if (rearNode) {
        rearNode->next = nullptr;
    } else {
        frontNode = nullptr;
    }
    delete temp;
    return value;
}

template <typename T>
T LinkedListDeque<T>::front() const {
    if (!frontNode) {
        throw std::out_of_range("Deque is empty");
    }
    return frontNode->value;
}

template <typename T>
T LinkedListDeque<T>::back() const {
    if (!rearNode) {
        throw std::out_of_range("Deque is empty");
    }
    return rearNode->value;
}

template <typename T>
bool LinkedListDeque<T>::isEmpty() const {
    return frontNode == nullptr;
}
