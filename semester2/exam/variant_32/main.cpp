//
// Created by Павло on 03.06.2024.
//

#include <iostream>
using namespace std;

// Task 1
// Поліном від однієї змінної з цілими коефіцієнтами можна подати звʼязним списком,
// впорядкованим за зростанням степені змінної, без зберігання одночленів з нульовими
// коефіцієнтами. Написати функцію, яка знаходить суму двох поліномів.
// Task 2
// Написати не рекурсивну функцію для друкування відміток вузлів бінарного дерева,
// поданого у «стандартній формі», при його проходженні у «порівневому порядку» (корінь,
// сини, сини синів, ...).
// Task 3
// Написати функцію, яка вилучає всі петлі «псевдо графа», поданого «структурою
// суміжності».

// task 1 ----------------------------------------------------------------------------------------------------

class Node {
public:
    double coef;
    double power;
    Node* next;
    Node* prev;

    explicit Node(int coef, double power) : coef(coef), power(power), next(nullptr), prev(nullptr) {}
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

    void append(int coef, double power) {
        Node* newNode = new Node(coef, power);
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

            cout << "(" << current->coef << ")x^(" << current->power << ")" << " + ";
            current = current->next;
        }
        cout << "0";
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


void task1(Node* firstHead, Node* secondHead){

    Node* currentInFirstList = firstHead;
    Node* currentInSecondList = secondHead;

    DoublyLinkedList finalList;

    while (currentInFirstList){
        if(currentInFirstList->power == currentInSecondList->power){
            int coef = currentInFirstList->coef + currentInSecondList->coef;
            finalList.append(coef, currentInFirstList->power);
            currentInFirstList = currentInFirstList->next;
            currentInSecondList = currentInSecondList->next;
        } else if(currentInFirstList->power > currentInSecondList->power){
            finalList.append(currentInSecondList->coef, currentInSecondList->power);
            currentInSecondList = currentInSecondList->next;
        }else{
            finalList.append(currentInFirstList->coef, currentInFirstList->power);
            currentInFirstList = currentInFirstList->next;
        }
    }
    while (currentInSecondList){
        finalList.append(currentInSecondList->coef, currentInSecondList->power);
        currentInSecondList = currentInSecondList->next;
    }

    finalList.displayByHead();


}


// task 2 ----------------------------------------------------------------------------------------------------

class TreeNode {
public:

    int value;
    TreeNode* left;
    TreeNode* right;
    //constructor
    explicit TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};


class BinarySearchTree{
private:
    TreeNode* root;


    void _addTo(TreeNode* node, int value){
        if(value < node->value ){
            if(node->left == nullptr){
                node->left = new TreeNode(value);
            }else{
                _addTo(node->left, value);
            }
        }else if(value > node->value){
            if(node->right == nullptr){
                node->right = new TreeNode(value);
            }else{
                _addTo(node->right, value);
            }

        }else{
            cout << "Node with given value already exist\n";
            return;
        }

    }


public:
    //constructor
    BinarySearchTree() : root(nullptr) {}

    TreeNode* getRoot(){
        return root;
    }
    void insert(int value){
        if(root== nullptr){
            root = new TreeNode(value);
            return;
        }
        _addTo(root, value);
    }

};

class QueueNode {
public:
    TreeNode* data;
    QueueNode* next;

    explicit QueueNode(TreeNode* value) : data(value), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    // method to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // method to enqueue (or push) value
    void enqueue(TreeNode* value) {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // method to dequeue (or pop) value
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
        } else {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // method to get the front value
    TreeNode* peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return nullptr;
        } else {
            return front->data;
        }
    }
};

void task2(TreeNode* root){
    if (root == nullptr) {
        return;
    }

    Queue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        TreeNode* current = q.peek();
        q.dequeue();

        cout << current->value << " ";

        if (current->left != nullptr) {
            q.enqueue(current->left);
        }

        if (current->right != nullptr) {
            q.enqueue(current->right);
        }
    }
    cout << '\n';
}

// task 3 ---------------------------------------------------------------------------------------------------------
const int rows = 4;
const int cols = 4;

class GraphNode {
public:
    int index; // index of matrix column
    GraphNode* next; // pointer to next element in the same row
    explicit GraphNode( int index) : index(index), next(nullptr) {}
};

class Graph {
    //adjacencyStructure
public:
    GraphNode* arr[4] = {nullptr};

    void convertMatrix(int matrix[rows][cols]){
        for(int row = 0; row < rows; row++){
            GraphNode* lastNodeInRow = arr[row];
            for(int col = 0; col < cols; col++){
                if(matrix[row][col] != 0){
                    GraphNode* newNode = new GraphNode(col);
                    if(arr[row] == nullptr){
                        arr[row] = newNode;
                    }else{
                        lastNodeInRow->next = newNode;
                    }
                    lastNodeInRow = newNode;

                }

            }
        }
    }

    void print(){
        for (int row = 0; row < rows; row++){
            cout << "node " << row+1 << " connected to: ";
            GraphNode* current = arr[row];
            while (current){
                cout << "(node: " << current->index+1 << "); ";
                current = current->next;
            }
            cout << "\n";
        }
    }
};


void task3(GraphNode* graphArr[]){
    for (int row = 0; row < rows; row++) {
        GraphNode* current = graphArr[row];
        GraphNode* prev = nullptr;
        while (current) {
            if (current->index == row) { // self-loop found
                if (prev == nullptr) { // loop is the first node in the row
                    graphArr[row] = current->next;
                } else {
                    prev->next = current->next;
                }
                GraphNode* temp = current;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

int main(){

    // task 1
//    DoublyLinkedList list1;
//    DoublyLinkedList list2;
//
//    list1.append(1, 2);
//    list1.append(10, 3);
//    list1.append(-3, 4);
//    list1.append(-10, 6);
//
//
//    list2.append(2, 1);
//    list2.append(-4, 3);
//    list2.append(5, 4);
//    list2.append(7, 5);
//    list2.append(2, 7);
//
//    list1.displayByHead();
//    list2.displayByHead();
//
//    task1(list1.getHead(), list2.getHead());

    // task 2

//    BinarySearchTree bst;
//    bst.insert(30);
//    bst.insert(25);
//    bst.insert(40);
//    bst.insert(15);
//    bst.insert(26);
//    bst.insert(36);
//    bst.insert(42);
//    bst.insert(34);
//    bst.insert(45);
//
//    task2(bst.getRoot());

    // task 3

    Graph graph;
    int matrixOfGraph[rows][cols]= {
            {0, 1, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 1},
    };
    graph.convertMatrix(matrixOfGraph);
    graph.print();

    cout << "\n\n";
    task3(graph.arr);
    graph.print();





    return 0;
}
