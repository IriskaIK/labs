//
// Created by Павло on 30.04.2024.
//
#include <iostream>
using namespace std;


// task 1
// В елементах зв'язного списку розміщенні різні цілі числа. Написати функцію, що роздруковує значення елементів
// розташованих між найменшим та найбільшим елементами

// task 2
// Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить відмітки вузлів бінарного
// дерева, поданого у "стандартній формі", по рівнях (починаючи з кореня дерева, далі з синів кореня й далі)

// task 3
// Написати функцію, що перевіря зв'язний граф, поданий "стурктурою суміжності", на ейлеровість

// task 1
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
    Node* getHead(){
        return head;
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

// In fact, you need only this function for exam.
// Node and DoublyLinkedList classes is more like environment for this function.
void task1(Node* head){
    // for exam you need only this function
    // find and display elements between Min and Max
    Node* current = head;

    int minIndex = 0;
    int maxIndex = 0;
    int currentIndex = 0;
    Node *minNode = head;
    Node *maxNode = head;

    while (current){
        if(current->data < minNode->data){
            minNode = current;
            minIndex = currentIndex;
        }else if(current->data > maxNode->data){
            maxNode = current;
            maxIndex = currentIndex;
        }
        currentIndex++;
        current = current->next;
    }

    Node* startFrom;
    Node* endBy;
    if(maxIndex > minIndex){
        startFrom = minNode;
        endBy = maxNode;
    }else{
        startFrom = maxNode;
        endBy = minNode;
    }
    Node* currentToPrint = startFrom;

    while (currentToPrint!=endBy->next){
        cout<< currentToPrint->data << "->";
        currentToPrint = currentToPrint->next;
    }
}
// task 1



// task 2
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
// task 2

// task 3

const int rows = 4;
const int cols = 4;

class GraphNode{
    //represent element of matrix in linked list

public:

    int value;// value of element
    int index; // index of element(aka number of element`s column in matrix)
    GraphNode* next; // pointer to next element (next element must be in the same row!)

    explicit GraphNode(int value, int index) : value(value), index(index), next(nullptr) {}
};

class rGraphNode{
    // represent row of matrix in linked list

public:
    int index; // index of matrix row
    GraphNode* head; // pointer to first(not zero) element of certain row
    GraphNode* tail; // pointer to last(not zero) element of certain row
    rGraphNode* nextRow; // pointer to next row of matrix

    void append(int value, int columnIndex){
        GraphNode* newNode = new GraphNode(value, columnIndex);

        if (head == nullptr) {

            //if there is 0 elements in list, then make new element a head
            head = newNode;

        }else if(tail == nullptr){
            //if there is no tail in list, then make new element a tail
            head->next = newNode;
            tail = newNode;
        }else {
            //insert new element after tail and mark it as a tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    explicit rGraphNode(int index) : index(index), head(nullptr), tail(nullptr), nextRow(nullptr) {};
};

class AdjacencyStructure{
private:
    rGraphNode* head;
    rGraphNode* tail;

public:
    explicit AdjacencyStructure() : head(nullptr){};

    void appendInRow( int columnIndex, int value){


        rGraphNode* rowNode = tail;
        rowNode->append(value, columnIndex);

    }

    rGraphNode* getHead(){
        return head;
    }

    void appendRow(int rowIndex){

        rGraphNode* rowNode = new rGraphNode(rowIndex);

        if(head == nullptr){
            head = rowNode;
            tail = rowNode;
        }else if(tail == nullptr){
            head->nextRow = rowNode;
            tail = rowNode;
        }else{
            tail->nextRow = rowNode;
            tail = rowNode;
        }

    }

    void convertMatrixToCompressedMatrix(int matrix[rows][cols]){

        for(int row = 0; row < rows; row++){
            appendRow(row);
            for(int col = 0; col < cols; col++){
                if(matrix[row][col] != 0){
//                    cout << "check " << row << ' ' << col << ' ';
                    appendInRow(col, matrix[row][col]);
                }

            }
        }
    }

    void displayCompressedMatrix(){
        rGraphNode* currentRow = head;
        while (currentRow){
            GraphNode* currentElement = currentRow->head;
            cout << '\n';
            cout << currentRow->index+1 << " have connection to: ";
            while (currentElement){
                cout <<  currentElement->index+1 << ", ";
                currentElement = currentElement->next;
            }
            currentRow = currentRow->nextRow;
        }
    }
};

void task3(AdjacencyStructure adjacencyStructure){
    // for exam you need only this function
    rGraphNode* currentRow = adjacencyStructure.getHead();
    while (currentRow){
        GraphNode* currentElement = currentRow->head;
        int evenCounter = 0;
        while (currentElement){
            evenCounter++;
            currentElement = currentElement->next;
        }
        if(evenCounter%2 != 0){
            cout << "The graph is not Eulerian";
            return;
        }
        currentRow = currentRow->nextRow;
    }
    cout << "The graph is Eulerian";
}

// task 3





int main(){

//  task 1

    DoublyLinkedList list;
    list.append(4);
    list.append(6);
    list.append(-1);
    list.append(2);
    list.append(10);
    list.append(5);
    list.append(0);
    list.append(4);
    list.append(-3);
    list.append(8);

    cout << "Task 1:\n";
    task1(list.getHead());
    cout << "\n\n";

    // task 2

    BinaryTree bt;
    bt.addNode(50);
    bt.addNode(10);
    bt.addNode(60);
    bt.addNode(5);
    bt.addNode(40);
    bt.addNode(55);
    bt.addNode(70);
    bt.addNode(1);
    bt.addNode(4);
    bt.addNode(20);
    bt.addNode(30);
    bt.addNode(75);
    bt.addNode(72);
    cout << "Task 2:\n";
    task2(bt.getRoot());
    cout << "\n\n";

    // task 3

    AdjacencyStructure adjacencyStructure;
    // environment of task 3 function, for exam you do not have to write all of this.
    // say that "you already have adjacencyStructure" and pass it as an argument to task 3 function.
    // class AdjacencyStructure also used in variant 72 task 3
    // here this class is needed only for visualisation of the adjacencyStructure
    int matrixOfGraph[rows][cols]= {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0},
    };
    adjacencyStructure.convertMatrixToCompressedMatrix(matrixOfGraph);
//    adjacencyStructure.displayCompressedMatrix();
    cout << "Task 3:\n";
    task3(adjacencyStructure);
    cout << "\n\n";

    return 0;
}