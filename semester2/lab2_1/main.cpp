
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

    void remove(Node** toDelete) {
        // check if linked list has elements

        if (head == nullptr) {
            return;
        }


        // search for element of LinkedList with given value

        if(*toDelete == head){
            cout << "here" << "\n";
            // if element is a head in the LinkedList than set next one as a head of linked list
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }else if(*toDelete == tail){
            // if element is a tail  in the LinkedList than set prev one as a tail of linked list
            tail->prev->next = head;
            tail = tail->prev;
            head->prev = tail;
        }else{
            (*toDelete)->prev->next = (*toDelete)->next;
            (*toDelete)->next->prev = (*toDelete)->prev;
        }



        // delete found element
        delete *toDelete;
    }

    // method to split list
    void split(DoublyCircularLinkedList &oddList) {
        Node* current = head;
        Node* firstEvenNode = nullptr;

        if (!current) return; // If list is empty == nullptr

        do {
            int value = current->data;
            Node* nextToCurrent = current->next;

            if (value % 2 == 0) {
                // pass
                if(!firstEvenNode){
                    firstEvenNode = current;
                }
            } else {

                oddList.add(value);
                remove(&current);

            }

            current = nextToCurrent;


        } while (current != firstEvenNode);
    }
};

int main() {
    DoublyCircularLinkedList list, oddList;

    // Insert elements inside main list
    //will work if in list al least one even element
    list.add(1);
    list.add(2);
    list.add(5);
    list.add(7);
    list.add(9);


    // will not work, because here only odd elements
    //TODO: fix bug with only odd elements
//    list.add(1);
//    list.add(3);
//    list.add(5);
//    list.add(7);
//    list.add(9);




    cout << "List before splissst: ";
    list.display();

    // Split list to odd and even lists
    list.split(oddList);

    cout << "List with odd numbers: ";
    oddList.display();

    cout << "List with even numbers: ";
    list.display();

    //main list will be deleted. See method clear

    return 0;
}