//
// Created by Павло on 09.06.2024.
//
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
public:
    Node* head;
    Node* tail;

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

};