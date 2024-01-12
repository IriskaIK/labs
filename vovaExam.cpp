//
// Created by Павло on 25.12.2023.
//
#include <iostream>
#include <cmath>
using namespace std;



void task1(){

}
void task2(char cstring[], int len){
    bool isPreviousSpace = false;

    if(cstring[0]!= ' '){
        cstring[0] = cstring[0] - 32;
    } else{
        isPreviousSpace = true;
    }
    for (int i = 1; i < len; ++i) {
        if(cstring[i] == ' '){
            isPreviousSpace = true;
        }
        if(isPreviousSpace and cstring[i] != ' '){
            cstring[i] = cstring[i] - 32;
            isPreviousSpace = false;
        }
    }
    cout << cstring;
}

const int rows = 3;
const int cols = 3;

struct element{
    int row;
    int col;
    int value;
};


element task3(int matrix[rows][cols]){
    bool isPreviousSmaller = false;

    element best;
    best.row = - 1;
    best.col = -1;
    best.value = 0;

    int previousNumber = 0;
    int currCol = -1;

    for(int i = 0; i < rows; i++){
        previousNumber = matrix[i][0];
//        cout<< previousNumber;
        for(int k = 1; k < cols and previousNumber!=-1; k++){
            currCol = k;
            if(matrix[i][k] > previousNumber){
                previousNumber = matrix[i][k];
            }
            else{
                previousNumber = -1;
            }

        }

        if(previousNumber > best.value){
            cout << previousNumber << '\n';
            best.value = previousNumber;
            best.col = currCol;
            best.row = i;
        }

    }
    return best;
}





int main(){

//    char some[59] = {"hello how are you dear friend i wish you a merry christmas"};
//    task2(some, 59);

    int matrix[rows][cols] = {
            {1, 2, 100},
            {100, 300, 1},
            {200, 400, 1}
    };
    element elem = task3(matrix);
    cout << elem.row << " " << elem.col << " " << elem.value;
    return 0;
}