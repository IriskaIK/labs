//
// Created by Павло on 08.06.2024.
//
#include <iostream>
using namespace std;

// task 1
// В елементах звʼязного циклічного списку розміщені цілі числа. Написати функцію, що
// впорядковує список, збираючи спочатку всі непарні числа, а потім - парні.
// task 2
// Написати не рекурсивну функцію (з використанням стека) для друкування відміток вузлів
// бінарного дерева, поданого у «стандартній формі», при його проходженні у «оберненому
// порядку».
// task 3
// Знайти всі вершини графа, що поданий структурую суміжності, які досяжні від заданої
// вершини.

// task 1 -------------------------------------------------------------------------------------------------------------
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

};


void task1(DoublyCircularLinkedList* list){
    Node* current = list->head;
    Node* firstEven = nullptr;
    while (current && current != firstEven){
        if(current->data % 2 == 0){
            Node* nextToCurrent = current->next;
            if(firstEven == nullptr){
                firstEven = current;
            }
            if(current == list->head){
                list->head = current->next;
                list->tail = current;
            }else{
                current->prev->next = current->next;
                current->next->prev = current->prev;

                current->prev = list->tail;
                list->tail->next = current;

                current->next = list->head;
                list->head->prev = current;

                list->tail = current;
            }
            current = nextToCurrent;
        }else{
            current = current->next;
        }
    }
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

class StackNode {
public:
    TreeNode* data;
    StackNode* next;

    explicit StackNode(TreeNode* value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    StackNode* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // checks if stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // method for adding new element to stack
    void push(TreeNode* value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }

    // method for removing top element of a stack
    void pop() {
        if (!isEmpty()) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // method for getting top element of a stack
    TreeNode* peek() const {
        // checks if stack is not empty
        if (!isEmpty()) {
            return top->data;
        }

        cout << "Stack is empty." << '\n';
        return nullptr;
    }
};

void task2(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    Stack s1, s2;
    s1.push(root);

    while (!s1.isEmpty()) {
        TreeNode* node = s1.peek();
        s1.pop();
        s2.push(node);


        if (node->left) {
            s1.push(node->left);
        }

        if (node->right) {
            s1.push(node->right);
        }



    }

    while (!s2.isEmpty()) {
        TreeNode* node = s2.peek();
        s2.pop();
        cout << node->value << " ";
    }
}

// task 3 -------------------------------------------------------------------------------------------------------------
const int rows = 4;
const int cols = 4;
class StackNode2 {
public:
    int data;
    StackNode2* next;

    explicit StackNode2(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack2 {
private:
    StackNode2* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack2() : top(nullptr) {}

    // Destructor to free memory
    ~Stack2() {
        while (!isEmpty()) {
            pop();
        }
    }

    // checks if stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // method for adding new element to stack
    void push(int value) {
        StackNode2* newNode = new StackNode2(value);
        newNode->next = top;
        top = newNode;
    }

    // method for removing top element of a stack
    void pop() {
        if (!isEmpty()) {
            StackNode2* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // method for getting top element of a stack
    int peek() const {
        // checks if stack is not empty
        if (!isEmpty()) {
            return top->data;
        }

        cout << "Stack is empty." << '\n';
        return -1;
    }
};
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


    void findReachable(int start) {
        bool visited[rows] = {false};

        Stack2 stack;

        stack.push(start);
        visited[start] = true;

        cout << "Nodes reachable from node " << start + 1 << ": ";

        while (!stack.isEmpty()) {
            int current = stack.peek();
            stack.pop();
            cout << current + 1 << " ";

            GraphNode* node = arr[current];
            while (node) {
                if (!visited[node->index]) {
                    stack.push(node->index);
                    visited[node->index] = true;
                }
                node = node->next;
            }
        }
        cout << "\n";
    }

};

int main(){

    // task 1
//    DoublyCircularLinkedList list;
//
//    list.add(2);
//    list.add(6);
//    list.add(1);
//    list.add(4);
//    list.add(3);
//    list.add(5);
//    list.add(8);
//    list.add(1);
//    list.display();
//
//    task1(&list);
//    list.display();

    // task 2
//    BinaryTree tree;
//    tree.addNode(1);
//    tree.addNode(2);
//    tree.addNode(3);
//    tree.addNode(4);
//    tree.addNode(5);
//    tree.addNode(6);
//    tree.addNode(7);
//    cout << "Postorder Traversal: ";
//    task2(tree.getRoot());
//    cout << "\n\n";

    // task 3

    Graph graph;
    int matrixOfGraph[rows][cols]= {
            {0, 1, 1, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {0, 1, 1, 0},
    };
    graph.convertMatrix(matrixOfGraph);
    graph.print();
    graph.findReachable(0);
    return 0;
}