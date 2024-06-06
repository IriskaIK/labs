//
// Created by Павло on 06.06.2024.
//

#include <iostream>
using namespace std;

// task 1
// Написати функцію для впорядкування за зростаючим порядком елементів списку у
// зв'язному зберіганні, використовуючи «сортування вибором».
// task 2
// Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить
// відмітки вузлів бінарного дерева, поданого у стандартній формі, по рівнях (починаючи з
// кореня дерева, далі з синів кореня й далі).
// task 3
// Написати функцію, яка перевіряє суміжність двох заданих вершин у неорієнтованому
// графі, що поданий структурою суміжності.

// task 1 ---------------------------------------------------------------------------------------------------------
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


void task1(DoublyLinkedList& list) {
    Node* head = list.getHead();
    if (head == nullptr) return;

    Node* start = head;
    while (start != nullptr) {
        Node* minNode = start;
        Node* current = start->next;
        while (current != nullptr) {
            if (current->data < minNode->data) {
                minNode = current;
            }
            current = current->next;
        }
        if (minNode != start) {
            int temp = start->data;
            start->data = minNode->data;
            minNode->data = temp;
        }
        start = start->next;
    }
}


// task 2 ---------------------------------------------------------------------------------------------------------

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void addNode(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
        } else {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                addNode(node->left, value);
            }
        }
    }

    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void addNode(int value) {
        addNode(root, value);
    }

    TreeNode* getRoot(){
        return root;
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
            return (front->data);
        }
    }
};

void task2(TreeNode* root){
    if(root == nullptr){
        return;
    }

    Queue queue;
    queue.enqueue(root);

    while (!queue.isEmpty()){

        TreeNode* current = queue.peek();
        cout << current->value << ',';

        if(current->left != nullptr){
            queue.enqueue(current->left);
        }if(current->right != nullptr){
            queue.enqueue(current->right);
        }

        queue.dequeue();

    }


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


bool task3(Graph& graph, int vertex1, int vertex2) {
    GraphNode* current = graph.arr[vertex1];
    while (current) {
        if (current->index == vertex2) {
            return true;
        }
        current = current->next;
    }

    return false;
}


int main(){

    // task 1
//    DoublyLinkedList list;
//    list.append(4);
//    list.append(2);
//    list.append(5);
//    list.append(1);
//    list.append(3);
//
//    cout << "Original List: ";
//    list.displayByHead();
//
//    task1(list);
//
//    cout << "Sorted List: ";
//    list.displayByHead();

    // task 2

//    BinaryTree bt;
//    bt.addNode(50);
//    bt.addNode(10);
//    bt.addNode(60);
//    bt.addNode(5);
//    bt.addNode(40);
//    bt.addNode(55);
//    bt.addNode(70);
//    bt.addNode(1);
//    bt.addNode(4);
//    bt.addNode(20);
//    bt.addNode(30);
//    bt.addNode(75);
//    bt.addNode(72);
//    cout << "Task 2:\n";
//    task2(bt.getRoot());
//    cout << "\n\n";

    // task 3

    Graph graph;
    int matrixOfGraph[rows][cols]= {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0},
    };
    graph.convertMatrix(matrixOfGraph);
    graph.print();
    if(task3(graph, 0, 1)){
        cout << "Are adjacent";
    }else{
        cout << "Are not adjacent";
    }




    return 0;
}