//
// Created by Павло on 09.06.2024.
//
#include <iostream>
using namespace std;


class CompactNode {
public:
    int data;
    int index;
    CompactNode* next;
    CompactNode* prev;

    explicit CompactNode(int value, int index) : data(value), index(index), next(nullptr), prev(nullptr) {}
};

class CompactLinkedList{
private:
    CompactNode* head;
    CompactNode* tail;

public:
    CompactLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int value, int index){
        auto* newNode = new CompactNode(value, index);
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

    void displayByHead() {
        CompactNode* current = head;
        if(current == nullptr){
            cout << "cannot display from head, because head doesnt exist" << '\n';
            return;
        }
        while (current != nullptr) {
            cout << "(value: " << current->data << "; index: " << current->index << ") => ";
            current = current->next;
        }
        cout << "None";
        cout << '\n';
    }

};