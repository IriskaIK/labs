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

// task 2

const int arrSize = 4;

class MatrixNode{
public:
    int rowIndex;
    int columnIndex;

    int data;

    MatrixNode* nextInRow;
    MatrixNode* nextInColumn;

    explicit MatrixNode(int rowIndex, int columnIndex, int data):
    rowIndex(rowIndex), columnIndex(columnIndex), data(data), nextInRow(nullptr), nextInColumn(nullptr) {}

};




void task2(){
    MatrixNode* rows[4];
    MatrixNode* cols[4];

    int matrix[4][4]={
            {0, 1, 2, 0},
            {0, 0, 0 ,1},
            {2, 0, 1, 0},
            {0, 4, 1,0}
    };
    // this code is representation of matrix above
    // you dont need this code
    // to be honest i dont want waste my time to write an algorithm, which will convert 2-D matrix array into this shit
    // soo dont pay attention to it, go to 170 line, there are code that you need for this task
    auto* el1 = new MatrixNode(0, 1, 1);
    auto* el2 = new MatrixNode(0, 2, 2);
    rows[0] = el1;
    cols[1]= el1;
    cols[2]= el2;
    el1->nextInRow = el2;
    auto* el3 = new MatrixNode(1, 3, 1);
    auto* el4 = new MatrixNode(2, 0, 2);
    auto* el5 = new MatrixNode(2, 2, 1);
    rows[1] = el3;
    rows[2]= el4;
    cols[3] = el3;
    cols[0] = el4;
    el2->nextInColumn = el5;
    el4->nextInRow = el5;
    auto* el6 = new MatrixNode(3, 1, 4);
    auto* el7 = new MatrixNode(3, 2, 1);
    rows[3] = el6;
    el1->nextInColumn = el6;
    el5->nextInColumn = el7;
    el6->nextInRow= el7;


    int finalMatrix[4][4] = {0};
    for(int i =0; i < arrSize; i++){
        for(int j = 0; j<arrSize; j++){

            MatrixNode* rNode = rows[i];
            MatrixNode* cNode = cols[j];
            int value = 0;
            while (rNode && cNode){

                if(rNode->columnIndex < cNode->rowIndex){
                    rNode = rNode->nextInRow;
                }
                else if(rNode->columnIndex > cNode->rowIndex){
                    cNode = cNode->nextInColumn;
                }
                else{
//                    cout << i << " " << j << " : " << rNode->data << " " << cNode->data << "\n";
//                    cout << rNode->rowIndex << " " << cNode->columnIndex << "\n\n";
                    value += (rNode->data) * (cNode->data);
                    rNode = rNode->nextInRow;
                    cNode = cNode->nextInColumn;
                }
            }
            finalMatrix[i][j] = value;
        }
    }


    for(int row = 0; row < arrSize; row++){
        cout << '\n';
        for(int col = 0; col < arrSize; col++){
            cout << finalMatrix[row][col] << " ";
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
//    DoublyLinkedList list;
//
//    list.append(5);
//    list.append(5);
//    list.append(10);
//    list.append(20);
//    list.append(20);
//    list.append(30);
//    list.append(40);
//    list.append(45);
//    list.append(45);
//    list.append(45);
//    list.append(50);
//    list.append(50);
//
//    list.displayByHead();
//    task1(&list);
//    list.displayByHead();


    // task 2
    task2();

    // task 3
//    TreeNode* root = nullptr;
//    root = insert(root, 5);
//    insert(root, 3);
//    insert(root, 2);
//    insert(root, 1);
//    insert(root, 6);
//    insert(root, 8);
//    int v = 4;
//    int count = task3(root, v);
//    cout << "Count of elements greater than: " << v << ", in binary tree: " << count << '\n';


    return 0;
}