//
// Created by Павло on 13.01.2024.
//
#include <iostream>
using namespace std;

//Implementation of stack using array.
//Using of array do not provide necessary dynamic for stack data structures.
//But here you can ?more easily? understand main concept of stack.
//See stack implementation using linked list in "dynamicStack.cpp"
//P.s. just try to understand this, and then move to queue ;)




class Stack {
private:
    static const int SIZE = 100;
    int arr[SIZE]{};
    int top;

public:
    Stack() {
        top = -1;  // Initialize the top of the stack
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top >= SIZE - 1) {
            cout << "Stack if full, cannot push element.\n";
            return;
        }
        top++;
        arr[top] = value;
        cout << "Pushed: " << value << "\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack is empty, cannot pop element\n";
            return;
        }
        cout << "Popped: " << arr[top] << "\n";
        top--;
    }

    // Function to get the top element without removing it
    int peek() {
        if (top < 0) {
            cout << "Stack is empty: ";
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack someStack;

    someStack.push(10);
    someStack.push(20);
    someStack.push(30);

    cout << "Top element: " << someStack.peek() << '\n';

    someStack.pop();

    cout << "Top element after pop: " << someStack.peek() << '\n';
    someStack.pop();
    someStack.pop();
    cout << someStack.peek() << '\n';

    cout << "Is the stack empty: " << (someStack.isEmpty() ? "Yes" : "No") << '\n';

    return 0;
}