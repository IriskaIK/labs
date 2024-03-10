//
// Created by Павло on 10.03.2024.
//

#include <iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;

    explicit Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList{
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
};



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

    DoublyLinkedList expandList(){
        int index = 0;
        CompactNode* current = head;
        DoublyLinkedList expandedList;
        while (current){
            if(index == current->index){

                expandedList.append(current->data);
                current = current->next;
                index++;
            }
            else{
                expandedList.append(0);
                index++;
            }
        }
        return expandedList;
    }

};


int main(){

    CompactLinkedList compactList;


    compactList.append(1, 3);
    compactList.append(2, 5);
    compactList.append(3, 6);
    compactList.append(4, 8);
    compactList.append(5, 15);
    compactList.append(6, 17);
    compactList.append(7, 20);

    compactList.displayByHead();

    DoublyLinkedList finalList = compactList.expandList();
    finalList.displayByHead();

    return 0;
}
