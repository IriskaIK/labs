//
// Created by Павло on 08.06.2024.
//

#include <iostream>
using namespace std;

// task 1
// Список F з цілих чисел, більшість елементів якого
// дорівнюють 0, представлений своїм звʼязним зберіганиям.
// Написати функцію для представлення F «стислим звʼязним зберіганням»
// task 2
// Написати функцію для знаходження у невпорядкованому
// бінарному дереві, що зберігається у «стандартній формі»,
// вершини з значенням v та рівня, де розташована ця вершина.
// task 3
// Написати функцію, яка за матрицею суміжності графа
// будує його структуру суміжності.

// task 1 -------------------------------------------------------------------------------------------------------------
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
    Node* getHead(){
        return head;
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

};


void task1(DoublyLinkedList* list){
    CompactLinkedList newList;

    Node* current = list->getHead();
    int index = 0;
    while (current){
        if(current->data!=0){
            newList.append(current->data, index);
        }
        index++;
        current = current->next;
    }

    newList.displayByHead();

}


// task 2 -------------------------------------------------------------------------------------------------------------

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

struct SearchResult {
    TreeNode* node;

    int depth;
};

SearchResult findNodeLevel(TreeNode* node, int v, int level) {
    if (node == nullptr) {
        return {nullptr, -1}; // Node not found
    }
    if (node->value == v) {
        return {node, level};
    }

    SearchResult leftResult = findNodeLevel(node->left, v, level + 1);
    if (leftResult.node != nullptr) {
        return leftResult;
    }
    return findNodeLevel(node->right, v, level + 1);
}

void task2(TreeNode* root, int v) {
    SearchResult result =  findNodeLevel(root, v, 1);

    if(result.depth != -1){
        cout << "level of node with value " << result.node->value << ": " << result.depth << "\n";
    } else{
        cout << "Node not found";
    }

}

// task 3 -------------------------------------------------------------------------------------------------------------
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

int main(){
    // task 1
//    DoublyLinkedList list;
//    list.append(0);
//    list.append(0);
//    list.append(1);
//    list.append(2);
//    list.append(0);
//    list.append(0);
//    list.append(0);
//    list.append(4);
//    list.append(0);
//    list.append(0);
//    list.append(0);
//    list.append(0);
//    list.append(0);
//    list.append(5);
//    list.append(0);
//    list.displayByHead();
//
//    task1(&list);

    // task 2

//    BinaryTree tree;
//    tree.addNode(1);
//    tree.addNode(2);
//    tree.addNode(3);
//    tree.addNode(4);
//    tree.addNode(5);
//    tree.addNode(6);
//    tree.addNode(7);
//
//    task2(tree.getRoot(), 7);


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



    return 0;
}