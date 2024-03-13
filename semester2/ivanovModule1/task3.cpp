//
// Created by Павло on 13.03.2024.
//

// написати функцію для побудови послідовно-зв'язного індексного зберігання розрідженної матриці B[10, 40]

// рядок 14 - задається розміри
// рядок 130 - задається матриця
// рядок 21 - клас елементу матриці
// рядок 34 - клас рядка матриці
// рядок 67 - клас зжатої матриці
// рядок 101 - метод, що приймає матрицю у вигляді двовимірного масиву і стискає її до зжатої матриці

#include <iostream>
using namespace std;


// set matrix params here
// отут задати розміри матриці, в нашому випадку 10 на 40
const int rows = 5;
const int cols = 4;


class Node{
    //represent element of matrix in linked list

public:

    int value;// value of element
    int index; // index of element(aka number of element`s column in matrix)
    Node* next; // pointer to next element (next element must be in the same row!)

    explicit Node(int value, int index) : value(value), index(index), next(nullptr) {}
};

class rNode{
    // represent row of matrix in linked list

public:
    int index; // index of matrix row
    Node* head; // pointer to first(not zero) element of certain row
    Node* tail; // pointer to last(not zero) element of certain row
    rNode* nextRow; // pointer to next row of matrix

    void append(int value, int columnIndex){
        Node* newNode = new Node(value, columnIndex);

        if (head == nullptr) {

            //if there is 0 elements in list, then make new element a head
            head = newNode;

        }else if(tail == nullptr){
//            cout << "check " << value << " " << columnIndex << ' ';
            //if there is no tail in list, then make new element a tail
            head->next = newNode;
            tail = newNode;
        }else {
            //insert new element after tail and mark it as a tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    explicit rNode(int index) : index(index), head(nullptr), tail(nullptr), nextRow(nullptr) {};
};

class CompressedMatrix{
private:
    rNode* head;
    rNode* tail;

public:
    explicit CompressedMatrix() : head(nullptr){};

    void appendInRow( int columnIndex, int value){


        rNode* rowNode = tail;
        rowNode->append(value, columnIndex);

    }

    void appendRow(int rowIndex){

        rNode* rowNode = new rNode(rowIndex);

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
        rNode* currentRow = head;
        while (currentRow){
            Node* currentElement = currentRow->head;
            cout << '\n';
            while (currentElement){
                cout << currentElement->value << "(" << currentRow->index << ", " << currentElement->index << ") -> ";
                currentElement = currentElement->next;
            }
            cout << "Null";
            currentRow = currentRow->nextRow;
        }
    }
};

int main(){
    CompressedMatrix someCompressedMatrix;

    // отут задається вхідна матриця, яку будемо компресувати у "послідовно-зв'язного індексного зберігання розрідженної матриці"
    int matrix[rows][cols] = {
            {1, 0, 0, 0},
            {0, 2, 0, 4},
            {6, 5, 0, 1},
            {1, 0 , 0, 0},
            {0, 0, 1, 2}
    };
    someCompressedMatrix.convertMatrixToCompressedMatrix(matrix);

    // display in format: value(row, column)
    someCompressedMatrix.displayCompressedMatrix();

    return 0;
}