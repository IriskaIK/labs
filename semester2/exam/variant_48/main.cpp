//
// Created by Павло on 06.06.2024.
//
#include <iostream>
using namespace std;

// task 1
// В елементах «звʼязного циклічного списку» розміщені цілі числа. Написати
// функцію, що розбиває множину поданих чисел на дві: з парними та непарними
// значеннями, використовуючи для множин представлення «звʼязними циклічними
// списками».
// task 2
// Написати функцію для перетворення виразу з цілих чисел та операцій «-», «/»,
// записаного у звичайній «інфіксній формі» у представлення в формі ПОЛІЗ.
// Потрібний стек реалізувати власноруч.
// task 3
// Написати функцію, яка для графа визначає всі вершини, відстань яких від заданої
// вершини v становить d. Граф представлений «структурою суміжності».


// task 1 -------------------------------------------------------------------------------------------------------------
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() : tail(nullptr), head(nullptr) {}

    ~DoublyCircularLinkedList() {
        clear();
    }

    void add(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            // if head doesn't exist yet - assign new node as a head and tail
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            //reassignment of pointers between new Node and Head
            newNode->next = head;
            head->prev = newNode;

            //reassignment of pointers between new Node and Tail
            tail->next = newNode;
            newNode->prev = tail;

            //assign New Node as a Head
            tail = newNode;
        }

    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << '\n';
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << '\n';
    }

    void clear() {
        while (tail != nullptr) {
            removeFirst();
        }
    }

    void removeFirst() {
        if (head == nullptr) return;

        if (head == tail) {
            // if so, we have 1 element inside linked list
            delete head;
            tail = nullptr;
            head = nullptr;
        } else {
            tail->next = head->next;
            head->next->prev = tail;
            delete head;

            head = tail->next;
        }
    }



    Node* getHead() const {
        return head;
    }
};


void task1_2(const DoublyCircularLinkedList& originalList, DoublyCircularLinkedList& evenList, DoublyCircularLinkedList& oddList) {
    Node* current = originalList.getHead();
    if (current == nullptr) return;

    do {
        if (current->data % 2 == 0) {
            evenList.add(current->data);
        } else {
            oddList.add(current->data);
        }
        current = current->next;
    } while (current != originalList.getHead());
}

// task 2 -------------------------------------------------------------------------------------------------------------


class StackNode {
public:
    int data;
    StackNode* next;

    explicit StackNode(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    StackNode* top; // Pointer to the top of the stack

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
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }

    // method for removing top element of a stack
    void pop() {
        if (!isEmpty()) {
            StackNode* temp = top;
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


int task2(char in[100]){
    Stack stack;

    for (int i = 0; in[i]; i++) {

        if (in[i] != ' ') {
            if (in[i]>47 and in[i]<58) {
                int num = 0;
                while (in[i]>47 and in[i]<58) {
                    num = num*10+in[i] - 48;
                    i++;
                }


                stack.push(num);
            }
            else {
                int result;
                if (in[i] == '-'){

                    int var1 = stack.peek();
                    stack.pop();
                    int var2 = stack.peek();
                    stack.pop();
                    result = var2-var1;

                    stack.push(result);
                }else if (in[i] == '/'){
                    int var1 =stack.peek();
                    stack.pop();
                    int var2 = stack.peek();
                    stack.pop();
                    result = var2/var1;
                    stack.push(result);
                }


            }
        }
    }
    return stack.peek();
}


// task 3 -------------------------------------------------------------------------------------------------------------
// i`m tired as fuck


int main(){

    // task 1
//    DoublyCircularLinkedList originalList;
//    originalList.add(1);
//    originalList.add(2);
//    originalList.add(3);
//    originalList.add(4);
//    originalList.add(5);
//
//    DoublyCircularLinkedList evenList;
//    DoublyCircularLinkedList oddList;
//
//    task1_2(originalList, evenList, oddList);
//
//    cout << "Original list: ";
//    originalList.display();
//
//    cout << "Even list: ";
//    evenList.display();
//
//    cout << "Odd list: ";
//    oddList.display();


    // task 2
//    char in[100] = "50 20 2 / - 20 5 / -";
//    cout << task2(in) << '\n';


    return 0;
}