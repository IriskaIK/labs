//
// Created by Павло on 13.03.2024.
//

// Ackerman function using stack

#include <iostream>
using namespace std;


class StackNode {
public:
    int m;

    StackNode* next;

    explicit StackNode(int m) : m(m), next(nullptr) {}
};


class Stack {
private:
    StackNode* top; // Pointer to the top of the stack


public:
    int size;
    // Constructor
    explicit Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // checks if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // method for adding new element to stack
    void push(int m) {
        StackNode* newNode = new StackNode(m);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // method for removing top element of a stack
    void pop() {
        if (!isEmpty()) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
        size--;
    }

    // method for getting top element of a stack
    StackNode peek() {
        // checks if stack is not empty
        if (!isEmpty()) {
            return *top;
        }

        cout << "Stack is empty." << '\n';
        return StackNode(-1);
    }
};


// Єбаніна яку я спиздив зі стак оверфлоу
int ackermann(int m, int n) {
    Stack stack;

    // zero iteration: adding starting value of m to stack
    stack.push(m);

    while (!stack.isEmpty()) {
        // checking if stack is not empty

        //getting element from stack(LIFO)
        StackNode current = stack.peek();
        stack.pop();


        if (current.m == 0) {
            // if m equal 0, we should add 1 to the n
            n = n + 1;
        } else if (n == 0) {
            // if n equal 0, we should reset n as a one, and add m-1 to stack
            n=1;
            stack.push(current.m - 1);
        } else if (current.m > 0 && n > 0) {
            // if m and n greater than 0, we should add m-1 and m to stack. reduce value of n by one
            stack.push(current.m - 1);
            stack.push(current.m);
            n = n - 1;
        }
    }

    // returning value of Ackerman function
    return n;
}

int main() {
    int m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;

    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << '\n';

    return 0;
}

