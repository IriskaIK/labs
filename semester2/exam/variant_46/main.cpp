//
// Created by Павло on 04.06.2024.
//
#include <iostream>
using namespace std;

//task 1
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

//task2
/* Написати функцію для обчислення значення виразу з цілих чисел та операцій "+", "*",
записаного у формі ПОЛІЗ. Потрібний стек реалізувати власноруч */

//task3
/* Написати функцію, яка для орієнтованого графа будує орієнтований граф
   з протилежною орієнтацією дуг. Графи представлені "структурами суміжності" */


// task 1 -------------------------------------------------------------------------------------------------------
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

    CompactNode* getHead(){
        return head;
    }
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

void task1(CompactNode* head, int i, int j){
    int nodesWithNonZeroValue = 0;

    CompactNode* current = head;
    while (current){
        if(current->index >= i && current->index < j){
            nodesWithNonZeroValue++;
            current = current->next;
        }else if(current->index == j){
            nodesWithNonZeroValue++;
            break;
        }else{
            break;
        }
    }
    cout << nodesWithNonZeroValue << '\n';
    cout << "quantity of zeroes: " << j-i-nodesWithNonZeroValue+1 << '\n';

}



// task 2 -------------------------------------------------------------------------------------------------------
class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

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
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // method for removing top element of a stack
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
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


int task2(char in[100]){
    Stack stack;

    for (int i = 0; in[i]; i++) {

        if (in[i] != ' ') {
            if (in[i]>47 and in[i]<58) {
                int num = 0;
                while (in[i]>47 and in[i]<58) {
                    num = num*10+in[i] - 48;
                    i++;
                }


                stack.push(num);
            }
            else {
                int result;
                if (in[i] == '+'){

                    result = stack.peek();
                    stack.pop();
                    result += stack.peek();
                    stack.pop();

                    stack.push(result);
                }else if (in[i] == '*'){
                    result = stack.peek();
                    stack.pop();
                    result *= stack.peek();
                    stack.pop();

                    stack.push(result);
                }


            }
        }
    }
    return stack.peek();
}




// task 3 -------------------------------------------------------------------------------------------------------

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
    Graph graphNew;

    for(int row = 0; row < rows; row++){
        GraphNode* current = graphArr[row];

        GraphNode* nodeToReverse = new GraphNode(row);

        while (current){
            cout << current->index << '\n';
            if(graphNew.arr[current->index]){
                nodeToReverse->next = graphNew.arr[current->index];
                graphNew.arr[current->index] = nodeToReverse;
            }else{
                graphNew.arr[current->index] = nodeToReverse;
            }
            current = current->next;
        }
    }
    graphNew.print();
}




int main(){
    // task 1
//    CompactLinkedList compactList;
//
//    compactList.append(1, 3);
//    compactList.append(2, 5);
//    compactList.append(3, 6);
//    compactList.append(4, 8);
//    compactList.append(5, 15);
//    compactList.append(6, 17);
//    compactList.append(7, 20);
//
//    compactList.displayByHead();
//
//    task1(compactList.getHead(), 1, 20);

    // task 2
//    char in[100] = "20 35 2 *+30 +";
//    cout << task2(in) << '\n';


    // task 3

    Graph graph;
    int matrixOfGraph[rows][cols]= {
            {0, 1, 1, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0},
    };
    graph.convertMatrix(matrixOfGraph);
    graph.print();
    cout << "\n\n";
    task3(graph.arr);

}