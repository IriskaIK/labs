//
// Created by Павло on 13.01.2024.
//
#include <iostream>
using namespace std;

class Queue {
private:
    static const int SIZE = 100;
    int arr[SIZE]{};
    int front, rear;

public:
    Queue() {
        front = -1;  // show position from where next dequeued element will go
        rear = -1; // show position from where next enqueued element will go
    }

    // Function to enqueue (add) an element to the queue
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full, cannot enqueue element.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;  // Adjust front when enqueuing the first element
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued " << value << " into the queue.\n";
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue element.\n";
            return;
        }

        cout << "Dequeued " << arr[front] << " from the queue.\n";
        front++;
        if (front > rear) {
            // Reset front and rear when the last element is dequeued
            front = -1;
            rear = -1;
        }
    }

    // Function to get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    Queue somequeue;

    somequeue.enqueue(10);
    somequeue.enqueue(20);
    somequeue.enqueue(30);

    cout << "Front element: " << somequeue.peek() << '\n';

    somequeue.dequeue();

    cout << "Front element after dequeue: " << somequeue.peek() << '\n';

    somequeue.dequeue();

    cout << "Front element after dequeue: " << somequeue.peek() << '\n';

    somequeue.dequeue();

    cout << "Is the queue empty? " << (somequeue.isEmpty() ? "Yes" : "No") << '\n';

    return 0;
}