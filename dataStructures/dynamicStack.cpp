//
// Created by Павло on 31.01.2024.
//

#include <iostream>
using namespace std;
//LIFO(Last in, first out)


//Implementation of stack using linked list.
//Firstly see "staticStack.cpp" to have some understanding of how stack works
//P.s. just try to understand this, and then move to queue ;)



// Node (single element of a stack)
class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // checks if stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // method for adding new element to stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // method for removing top element of a stack
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // method for getting top element of a stack
    int peek() const {
        // checks if stack is not empty
        if (!isEmpty()) {
            return top->data;
        }

        cout << "Stack is empty." << '\n';
        return -1;
    }
};

int main() {

    Stack someStack;

    someStack.push(10);
    someStack.push(20);
    someStack.push(30);
    someStack.push(40);
    someStack.push(50);

    cout << "Top element: " << someStack.peek() << '\n';

    someStack.pop();
    cout << "Top element: " << someStack.peek() << '\n';

    return 0;
}


