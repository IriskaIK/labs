//
// Created by Павло on 26.02.2024.
//
//
// Created by Павло on 26.02.2024.
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

    // method to split list
    void split(DoublyCircularLinkedList &oddList, DoublyCircularLinkedList &evenList) {
        Node* current = head;

        if (!current) return; // If list is empty == nullptr

        do {
            int value = current->data;
            if (value % 2 == 0) {
                evenList.add(value);
            } else {
                oddList.add(value);
            }
            current = current->next;
        } while (current != head);
    }
};

int main() {
    DoublyCircularLinkedList list, oddList, evenList;

    // Insert elements inside main list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "List before split: ";
    list.display();

    // Split list to odd and even lists
    list.split(oddList, evenList);

    cout << "List with odd numbers: ";
    oddList.display();

    cout << "List with even numbers: ";
    evenList.display();

    //main list will be deleted. See method clear

    return 0;
}