//
// Created by Павло on 30.04.2024.
//
#include <iostream>
using namespace std;

// task 1
// Написати функцію, яка у списку, що зберігається у зв'язному представленні,
// з кожної групи сусідніх елементів залишає лише один

// task 2
// Написати функцію для обчислення матриці B=A^2, де для матриці А використано
// прямокутне-зв'язне стисле зберігання, а матриця В зберігається традиційним чином
// у вигляді двовимірного масиву

// task 3
// Написати функцію, яка обчислює кількість елементів більших за v у множині, що
// представлена невпорядкованим бінарним деревом у "стандартній формі"

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

    Node* getHead(){
        return head;
    }

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

void task1(DoublyLinkedList* list){
    Node* current = list->getHead();

    while (current){

        if(current->next == nullptr){
            break;
        }
        if(current->data == current->next->data){
            // to be honest you dont have to change "prev" field of nodes, code will work without it
            // but we are using doubly linked list, so it will be right
            current->next = current->next->next;
            if(current->next){
                current->next->prev = current;
            }

        }else{
            current = current->next;
        }
    }

}








struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr)
        return new TreeNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int task3(TreeNode* root, int v){
    if (root == nullptr) {
        return 0;
    }

    // Рекурсивно обчислюємо кількість у лівому та правому піддереві
    int leftCount = task3(root->left, v);
    int rightCount = task3(root->right, v);

    // Якщо поточний вузол має значення більше за v, додаємо 1
    if (root->data > v) {
        return 1 + leftCount + rightCount;
    } else {
        return leftCount + rightCount;
    }
}


int main(){

    // task 1
    DoublyLinkedList list;

    list.append(5);
    list.append(5);
    list.append(10);
    list.append(20);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(45);
    list.append(45);
    list.append(45);
    list.append(50);
    list.append(50);

    list.displayByHead();
    task1(&list);
    list.displayByHead();


    // task 2


    // task 3
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);
    insert(root, 6);
    insert(root, 8);
    int v = 4;
    int count = task3(root, v);
    cout << "Count of elements greater than: " << v << ", in binary tree: " << count << '\n';


    return 0;
}