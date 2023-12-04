//
// Created by Павло on 04.12.2023.
//
//exam paper 13

#include <iostream>
#include <cmath>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(double A[], int I[], int n){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (A[I[j]] > A[I[j + 1]]) {
                swap(I[j], I[j + 1]);
            }
        }
    }
}

void selectionSort(double A[], int I[], int n){

    for(int i = 0; i < n-1; i++){
        int indOfMin = i;
        for(int k = i+1; k < n; k++){
            if (A[I[indOfMin]] > A[I[k]]){
                indOfMin = k;
            }
        }
        if(indOfMin!=i){
            swap(I[i], I[indOfMin]);
        }

    }
}

void task1(double A[], int n) {

    int I[n];

    for (int i = 0; i < n; ++i) {
        I[i] = i;
    }
//    bubbleSort(A, I, n);
    selectionSort(A, I, n);

    cout << "Task 1\nIndex array: ";
    for (int i = 0; i < n; ++i) {
        cout << I[i] << " ";
    }
    cout << "\n\n";
}

struct DecartPoint{
    float x;
    float y;
    void print(){
        cout << "Decart point\nx: " << x << "; y: " << y << ";\n";
    }
};

struct PolarPoint{
    float r;
    float deg;
    void print(){
        cout << "Polar point\nradius: " << r << "; degree: " << deg << ";\n";
    }
};


void task2(DecartPoint point){
    cout << "Task 2\n";
    point.print();

    PolarPoint polarPoint;
    polarPoint.r = sqrt(pow(point.x, 2) + pow(point.y, 2));
    polarPoint.deg = atan(point.y/point.x);

    polarPoint.print();

}

void task3(char cstring[], int n){
    int evenLen = n/2;
    int oddLen = (n/2) + (n%2);


//    cout << evenLen << '\n' << oddLen;


    char even_chars[evenLen];
    char odd_chars[oddLen];

    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            odd_chars[even_count++] = cstring[i];
        } else {
            even_chars[odd_count++] = cstring[i];
        }
    }

//    cout << even_chars << '\n' << odd_chars << '\n';

    int index = 0;

    for (int i = 0; i < evenLen; ++i) {
        cstring[index++] = even_chars[i];
    }
    for (int i = oddLen - 1 ; i >= 0; --i) {
        cstring[index++] = odd_chars[i];
    }


}


int main() {

    //Task 1
    double A[] = { 1.0, 3.14, 2.5, 0.5, 0.5, 200};
    int len = 6;
    task1(A, len);
    //

    //Task 2
    DecartPoint point = {1,1};
    task2(point);
    //

    //Task 3
    char cstring[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'z'};
    int stringLen = 8;
    task3(cstring, stringLen);
    cout << "\nTask 3\n" << cstring;
    //

    return 0;
}