#include "array_deque.h"
#include <stdexcept>

template <typename T>
void ArrayDeque<T>::pushFront(const T& element) {
    items.insert(items.begin(), element);
}

template <typename T>
void ArrayDeque<T>::pushBack(const T& element) {
    items.push_back(element);
}

template <typename T>
T ArrayDeque<T>::popFront() {
    if (!items.empty()) {
        T item = items.front();
        items.erase(items.begin());
        return item;
    }
    throw std::out_of_range("Deque is empty");
}

template <typename T>
T ArrayDeque<T>::popBack() {
    if (!items.empty()) {
        T item = items.back();
        items.pop_back();
        return item;
    }
    throw std::out_of_range("Deque is empty");
}

template <typename T>
T ArrayDeque<T>::front() const {
    if (!items.empty()) {
        return items.front();
    }
    throw std::out_of_range("Deque is empty");
}

template <typename T>
T ArrayDeque<T>::back() const {
    if (!items.empty()) {
        return items.back();
    }
    throw std::out_of_range("Deque is empty");
}

template <typename T>
bool ArrayDeque<T>::isEmpty() const {
    return items.empty();
}
