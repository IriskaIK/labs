#include "array_stack.h"
#include <stdexcept>

template <typename T>
void ArrayStack<T>::push(const T& element) {
    items.push_back(element);
}

template <typename T>
T ArrayStack<T>::pop() {
    if (!items.empty()) {
        T item = items.back();
        items.pop_back();
        return item;
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (!items.empty()) {
        return items.back();
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return items.empty();
}
