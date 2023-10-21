//
// Created by Pavel on 27.09.2023.
//
#include <iostream>
#include <cmath>
using namespace std;


int* transformNumToArray(long number){
    int* arr = new int[50];
    int i = 0;
    while (number != 0){
        arr[i+1] = number % 10;
        number = number / 10;
        i++;
    }
    arr[0] = i;

    return arr;
};

int* calculateSumOfSides(int numInArr[]){
    int length = numInArr[0];
    int left = 0, right = 0;
    int* sum = new int[2];

    int halfOfLength = length / 2;
    if(length%2 != 0){
        halfOfLength++;
    }

    for(int i = 0; i < halfOfLength; i++){
        right+= numInArr[i+1];
        left+= numInArr[length-i];
    }
    sum[0] = right;
    sum[1] = left;
    return sum;

}

int main(){
    int num;
    cout << "Enter number:" << '\n';
    cin >> num;
    int* numDigits = transformNumToArray(num);

    int* sumOfSides = calculateSumOfSides(numDigits);
    cout << "Left: " << sumOfSides[1] << '\n';
    cout << "Right: " << sumOfSides[0] << '\n';


    return 0;



}