//
// Created by Павло on 10.03.2024.
//


#include <iostream>
using namespace std;


// set matrix params here
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

    void appendRow(int rowIndex, int columnIndex, int value){

        rNode* currentRow = head;
        rNode* rowNode = nullptr;
        while (currentRow){
            if(currentRow->index == rowIndex){

                rowNode = currentRow;

                break;
            }
            currentRow = currentRow->nextRow;
        }
        if(!rowNode){
           rowNode = new rNode(rowIndex);
           if(head == nullptr){
                head = rowNode;
           }else if(tail == nullptr){
                head->nextRow = rowNode;
                tail = rowNode;
           }else{
                tail->nextRow = rowNode;
                tail = rowNode;
           }
        }

        rowNode->append(value, columnIndex);

    }

    void convertMatrixToCompressedMatrix(int matrix[rows][cols]){

        for(int row = 0; row < rows; row++){

            for(int col = 0; col < cols; col++){
                if(matrix[row][col] != 0){
//                    cout << "check " << row << ' ' << col << ' ';
                    appendRow(row, col, matrix[row][col]);
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
    int matrix[rows][cols] = {
            {1, 0, 0, 0},
            {0, 2, 0, 4},
            {6, 5, 0, 1},
            {0, 0 , 3, 0},
            {0, 0, 1, 2}
    };
    someCompressedMatrix.convertMatrixToCompressedMatrix(matrix);

    // display in format: value(row, column)
    someCompressedMatrix.displayCompressedMatrix();

    return 0;
}