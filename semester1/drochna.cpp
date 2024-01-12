//
// Created by Павло on 18.12.2023.
//

#include <iostream>
#include <cmath>
using namespace std;

void getValueForY(int value, int resultArray[], int lastIndex){
    if(lastIndex > 999){
        return;
    }
    int finalValue = (2*value) + 1;
    resultArray[lastIndex] = finalValue;
}

void getValueForZ(int value, int resultArray[], int lastIndex){
    if(lastIndex > 999){
        return;
    }
    int finalValue = (3*value) + 1;
    resultArray[lastIndex] = finalValue;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void bubbleSort(int A[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}



int main(){

    int arr[1000];
    arr[0] = 1;
    int index = 0;
    int lastIndex = 1;


    for(index=0; index<1000; index++){

        if(lastIndex>999){
            break;
        }

        int k = arr[index];

        getValueForY(k, arr, lastIndex);
        lastIndex++;
        getValueForZ(k, arr, lastIndex);
        lastIndex++;

    }

    for(int i=0; i < 100; i++){
        cout << "i:" << i << ";  " <<arr[i] << '\n';
    }

    cout << "\n\n\n\n\n";
    bubbleSort(arr, 999);


    for(int k=0; k < 100; k++){
        cout << "i:" << k << ";  " <<arr[k] << '\n';
    }







    return 0;
}

