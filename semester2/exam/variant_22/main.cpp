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


// task 3

const int rows = 4;
const int cols = 4;

class GraphNode {
public:
    int index; // index of matrix column
    GraphNode* next; // pointer to next element in the same row
    explicit GraphNode( int index) : index(index), next(nullptr) {}
};

class Graph {
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


void findVerticesAtDistanceUtil(int current, int currentDistance, int distance, bool* result, bool* visited,
                                GraphNode* GraphArr[]){
    if (currentDistance == distance){

        result[current] = true; // mark as reachable
        return;
    }
    visited[current] = true;
    GraphNode* neighbor = GraphArr[current];
    while (neighbor){
        if (!visited[neighbor->index]){
            findVerticesAtDistanceUtil(neighbor->index, currentDistance + 1,
                                       distance, result, visited, GraphArr);
        }
        neighbor = neighbor->next;
    }
    visited[current] = false; // backtrack to allow other paths
}

void task3(int startVertex, int distance, bool* result, GraphNode* GraphArr[]){
    if (distance < 0 || startVertex < 0 || startVertex >= rows)
    return;

    bool visited[rows] = {false};
    for (int i = 0; i < rows; ++i) {
        result[i] = false;
    }

    findVerticesAtDistanceUtil(startVertex, 0, distance, result, visited, GraphArr);


    cout << "Vertices at distance " << distance << " from vertex " << startVertex + 1 << " are: ";
    for (int i = 0; i < rows; i++){
        if (result[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << '\n';
}


int main(){
    // task 1
//    LinkedList list;
//
//    list.append(10);
//    list.append(20);
//    list.append(40);
//    list.append(50);
//    list.append(60);
//    list.append(70);
//    list.displayByHead();
//
//    task1(list.getHead());

    // task 2



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

    int startVertex = 0; // example starting vertex (0-based index)
    int distance = 3; // example distance

    bool result[rows];

    task3(startVertex, distance, result, graph.arr);



}