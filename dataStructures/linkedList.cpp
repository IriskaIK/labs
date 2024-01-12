//
// Created by Павло on 12.01.2024.
//
#include <iostream>
#include <cmath>
using namespace std;

// Node class to represent each element in the doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    explicit Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            //if there is 0 elements in linked list, then make new element a head
            head = newNode;

        }else if(tail == nullptr){
            //if there is no tail in linked list, then make new element a tail
            head->next = newNode;
            newNode->prev = head;
            tail = newNode;
        }else {
            //insert new element after tail and mark it as a tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertBefore(int value, Node* afterNode){
        if (afterNode == nullptr) {
            // Invalid existingNode, do nothing
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = afterNode;
        newNode->prev = afterNode->prev;

        if (afterNode->prev != nullptr) {
            afterNode->prev->next = newNode;
        } else {
            // If afterNode is the head, update head
            head = newNode;
        }

        afterNode->prev = newNode;
    }

    void insertAfter(int value, Node* beforeNode){
        if (beforeNode == nullptr) {
            // Invalid existingNode, do nothing
            return;
        }

        Node* newNode = new Node(value);
        newNode->prev = beforeNode;
        newNode->next = beforeNode->next;

        if (beforeNode->next != nullptr) {
            beforeNode->next->prev = newNode;
        }else{
            tail = newNode;
        }

        beforeNode->next = newNode;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if (head == nullptr) {
            //if there is 0 elements in linked list, then make new element a head
            head = newNode;

        }else if(tail == nullptr){
            //if there is no tail in linked list, then make new element a tail
            tail = head;
            head = newNode;
            tail->prev = head;
            head->next = tail;

        }else {
            //insert new element before head and mark it as a head
            head->prev = newNode;
            newNode->next=head;
            head=newNode;
        }
    }



    void displayByHead() {
        Node* current = head;
        if(current == nullptr){
            cout << "cannot display from head, because head doesnt exist" << '\n';
            return;
        }
        while (current != nullptr) {
            cout << current->data << " => ";
            current = current->next;
        }
        cout << "None";
        cout << '\n';
    }

    void displayByTail() {
        Node* current = tail;
        if(current == nullptr){
            cout << "cannot display from tail, because tail doesnt exist" << '\n';
            return;
        }
        while (current != nullptr) {
            cout << current->data << " <= ";
            current = current->prev;
        }
        cout << "None";
        cout << '\n';
    }

    void remove(int value) {
        // check if linked list has elements
        if (head == nullptr) {
            return;
        }

        Node* current = head;

        // search for element of LinkedList with given value
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // if element with given value was not found
        if (current == nullptr) {
            return;
        }


        if(current->prev == nullptr){
            // if element is a head in the LinkedList than set next one as a head of linked list
            head = current->next;
        }else if(current->next == nullptr){
            // if element is a head in the LinkedList than set next one as a head of linked list
            tail->prev->next = nullptr;
            tail = tail->prev;
        }else{
            // if current element is not head or tail in the LinkedList than connect previous element of current with next element of current
            current->prev->next = current->next;
            // if current element is not head or tail in the LinkedList than connect next element of current with previous element of current
            current->next->prev = current->prev;
        }



        // delete found element
        delete current;
    }
    Node* search(int value) {
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }
//        cout << current->data;
        return current; // Returns nullptr if node with given value is not found
    }

    // Destructor to free memory occupied by the linked list
    // it called when an object goes out of scope
    ~DoublyLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.prepend(30);
    list.append(40);
    list.prepend(50);



    cout << "Doubly Linked List (From head): ";
    list.displayByHead();

    cout << "Doubly Linked List (From tail): ";
    list.displayByTail();

    list.remove(20);

    cout << "Doubly Linked List after removing 20: ";
    list.displayByHead();


    list.insertAfter(100,list.search(30));
    list.insertBefore(200, list.search(30));
    list.displayByHead();

    return 0;
}
