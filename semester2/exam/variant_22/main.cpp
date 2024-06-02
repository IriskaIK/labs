//
// Created by Павло on 02.06.2024.
//
// task 1
// Написати функцію для копіювання списку у «однозвʼязному представленні», зберігаючи
// взаємний порядок елементів, але зробивши у копії «двозвʼязне циклічне представлення».
// task 2
// Написати функцію для визначення висоти «дерева степені 3», що зберігається у
// «розширеній стандартній формі».
// task 3
// Знайти всі вершини графа, що поданий «структурую суміжності», до яких існує шлях
// заданої довжини d від заданої вершини


#include <iostream>
using namespace std;

// task 1
class NodeL {
public:
    int data;
    NodeL* next;

    explicit NodeL(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    NodeL* head;

public:
    LinkedList() : head(nullptr) {}

    NodeL* getHead(){
        return head;
    }
    void append(int value) {
        NodeL* newNode = new NodeL(value);
        if (head == nullptr) {

            head = newNode;

        }else {
            newNode->next = head;
            head = newNode;
        }
    }

    void displayByHead() {
        NodeL* current = head;
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


    // Destructor to free memory occupied by the linked list
    // it called when an object goes out of scope
    ~LinkedList() {
        NodeL* current = head;
        NodeL* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

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

    ~DoublyCircularLinkedList() {
        while (tail != nullptr){
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
    }
};


void task1(NodeL* headOfListToCopy){
    DoublyCircularLinkedList list;

    list.head = new Node(headOfListToCopy->data);
    NodeL* current = headOfListToCopy->next;
    while (current){
        if(list.tail == nullptr){
            list.tail = new Node(current->data);
            list.head->next = list.tail;
            list.tail->prev = list.head;
        }else{
            Node* newElement = new Node(current->data);
            newElement->prev = list.tail;
            list.tail->next = newElement;
            list.tail = newElement;
        }
        current = current->next;
    }
    list.head->prev = list.tail;
    list.tail->next = list.head;

    list.display();

};

int main(){
    // task 1
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(40);
    list.append(50);
    list.append(60);
    list.append(70);
    list.displayByHead();

    task1(list.getHead());

    // task 2

}