//
// Created by Павло on 14.05.2024.
//
#include <iostream>
using namespace std;

// task 1
// Поліном від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, впорядкованим за зростанням
// степені змінної, без зберігання одночленів з нульовими коефіцієнтами. Написати функцію, яка реалізує обчислення
// похідної від поліному

// task 2
// Написати функцію для сортування масиву методом "визначення позиції"
// (I. Порівняннями кожного елементу з іншими визначають кількість менших за нього(k). Це визначає місце елемента
// у впорядкованому масиві(k+1). II. Переставляють елементи згідно з їх місцями.).

// task 3
// Побудувати "дерево двійкового пошуку" за заданою множиною цілих чисел й занумерувати його вершини згідно з обходом
// у "симетричному порядку"

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



void task1(Node* head){
    Node* current = head;

    while (current){

        double power = current->power;
        current->power = current->power - 1;
        current->coef = current->coef * power;

        current= current->next;
    }
}

void task2_1(int arr[], int size){
    int n = size;
    int sortedArr[n];

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] < arr[i] || (arr[j] == arr[i] && j < i)) {
                ++k;
            }
        }
        sortedArr[k] = arr[i];
    }

    for(int i = 0; i<n; i++){
        cout << sortedArr[i] << " ";
    }
    cout << '\n';
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void task2_2(int arr[], int size) {
    // don't work for array where you have repeated numbers
    int n = size;

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {

        // Порівняння з усіма іншими елементами і підрахунок кількості менших
        int k = 0;
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]){
                k++;
            }
        }
        if(k!=0){
            swap(arr[i], arr[i+k]);
            if (i!=n-1) i--;
        }

    }

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';

}




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
    void _inorderTraversal(TreeNode* node, int& counter) {
        if (node == nullptr){
            return;
        }
        _inorderTraversal(node->left, counter);
        cout << "Node " << ++counter << ": " << node->value << "\n";
        _inorderTraversal(node->right, counter);
    }


public:
    //constructor
    BinarySearchTree() : root(nullptr) {}

    void insert(int value){
        if(root== nullptr){
            root = new TreeNode(value);
            return;
        }
        _addTo(root, value);
    }

    void inorderTraversal() {
        int counter = 0;
        _inorderTraversal(root, counter);
    }

};

void task3(int arr[], int size){
    BinarySearchTree bst;
    // побудова дерева
    for(int i = 0; i < size; i++){
        bst.insert(arr[i]);
    }
    // пронумерований вивід вершин у симетричному порядку
    bst.inorderTraversal();
}

int main(){

    // task 1
//    DoublyLinkedList list;
//
//    list.append(4, -3);
//    list.append(4, 0.5);
//    list.append(3, 1);
//    list.append(2, 2);
//    list.append(-3, 3);
//    list.append(6, 4);
//    list.append(1, 5);
//
//    list.displayByHead();
//    task1(list.getHead());
//    list.displayByHead();

    // task 2

    int arr[6] = {5, 2, 9, 1, 5, 6};

    // Завдання трошки кончене, і не понятно що значить "місце елемента у впорядкованому масиві(k+1)"..
    // Це значить, що ми визначаємо місце в оригінальному масиві, чи в новому масиві, який вже буде впорядкований
    // Тому є дві реалізації: перша створює новий масив в який будуть записуватись значення на потрібне місце
    // друга одразу в оригінальному масиві ставить на місце елемент, міняючи його місцями з тим, що був на тому
    // місці до того
    // Короче, спитайте іванова, який варіант йому потрібен і перепишіть той, що він попросить.

//    task2_1(arr, 6);


    // task 3
    task3(arr, 6);



    return 0;
}


