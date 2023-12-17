//
// Created by Павло on 16.12.2023.
//
#include <iostream>
using namespace std;


const int rows = 3;
const int cols = 3;

//int findMostRepeatedElement(int matrix[rows][cols]) {
//    int maxCount = 0;
//    int maxRepeatedElement = matrix[0][0];
//
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            int currentElement = matrix[i][j];
//            int currentCount = 0;
//
//            for (int k = 0; k < rows; ++k) {
//                for (int l = 0; l < cols; ++l) {
//                    if (matrix[k][l] == currentElement) {
//                        ++currentCount;
//                    }
//                }
//            }
//            if(maxRepeatedElement < currentElement and currentCount>=2){
//                maxRepeatedElement = currentElement;
//            }
//
//
//        }
//    }
//
//    return maxRepeatedElement;
//}


int isInArray(int array[rows*cols][2], int element){
    for (int k = 0; k < rows*cols; k++){
        if(array[k][0] == element){
            return k;
        }

    }
    return -1;
}

int findMaxElementWithTwoEntry(int matrix[rows][cols]){
    int arrayOfElementsEntrys[rows*cols][2] = {0};
    int helperArrayCounter = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "matrix element: " << matrix[i][j] << '\n';


            int indexInHelperArray = isInArray(arrayOfElementsEntrys, matrix[i][j]);

            if(indexInHelperArray == -1){
                arrayOfElementsEntrys[helperArrayCounter][0] = matrix[i][j];
                arrayOfElementsEntrys[helperArrayCounter][1] = 1;
                helperArrayCounter++;
            }else{
                arrayOfElementsEntrys[indexInHelperArray][1]++;
            }


        }
    }
//    cout << '\n' << arrayOfElementsEntrys[2][0] << ' ' << arrayOfElementsEntrys[2][1] << '\n';
    //on this step we alrady have 2d array with key value, where key is element from matrix and value is quantity of its entrys into matrix
    int best = -1;
    for(int i = 0; i <=helperArrayCounter; i++){
        if(arrayOfElementsEntrys[i][1] < 2){
            continue;
        }
        if(arrayOfElementsEntrys[i][0] > best){
            best = arrayOfElementsEntrys[i][0];
        }
    }


    return best;
}

int main() {
    int matrix[rows][cols] = {
            {100, 2, 3},
            {4, 2, 1},
            {2, 1, 99}
    };

    int result = findMaxElementWithTwoEntry(matrix);

    cout << result << endl;

    return 0;
}