//
// Created by Павло on 31.01.2024.
//
#include <iostream>
using namespace std;
//FIFO(first in, first out)

//Implementation of queue using linked list.
//Firstly see "staticQueue.cpp" to have some understanding of how queue works

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    // method to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // method to enqueue (or push) value
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // method to dequeue (or pop) value
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // method to get the front value
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1;
        } else {
            return front->data;
        }
    }
};

int main() {
    Queue someQueue;

    someQueue.enqueue(10);
    someQueue.enqueue(20);
    someQueue.enqueue(30);

    cout << "Front element: " << someQueue.peek() << "\n";

    someQueue.dequeue();

    cout << "Front element: " << someQueue.peek() << "\n";

    someQueue.dequeue();
    cout << "Front element: " << someQueue.peek() << "\n";
    someQueue.dequeue();
    cout << "Front element: " << someQueue.peek() << "\n";

    return 0;
}
