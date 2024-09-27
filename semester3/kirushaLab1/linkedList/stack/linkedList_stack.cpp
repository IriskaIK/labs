#include "linkedList_stack.h"
#include <stdexcept>

template <typename T>
LinkedListStack<T>::LinkedListStack() : head(nullptr) {}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void LinkedListStack<T>::push(const T& element) {
    StackNode<T>* newNode = new StackNode<T>(element);
    newNode->next = head;
    head = newNode;
}

template <typename T>
T LinkedListStack<T>::pop() {
    if (!head) {
        throw std::out_of_range("Stack is empty");
    }
    StackNode<T>* temp = head;
    T value = temp->value;
    head = head->next;
    delete temp;
    return value;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    if (!head) {
        throw std::out_of_range("Stack is empty");
    }
    return head->value;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return head == nullptr;
}
