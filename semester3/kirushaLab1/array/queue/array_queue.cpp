#include "array_queue.h"
#include <stdexcept>

template <typename T>
void ArrayQueue<T>::enqueue(const T& element) {
    items.push_back(element);
}

template <typename T>
T ArrayQueue<T>::dequeue() {
    if (!items.empty()) {
        T item = items.front();
        items.erase(items.begin());
        return item;
    }
    throw std::out_of_range("Queue is empty");
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (!items.empty()) {
        return items.front();
    }
    throw std::out_of_range("Queue is empty");
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return items.empty();
}
