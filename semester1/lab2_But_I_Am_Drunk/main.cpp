//
// Created by Павло on 14.12.2023.
//


#include <iostream>
#include <cmath>
using namespace std;

// Вибачте, але я вже бахнув півка в честь екзамена з аг))) я доздам друге завдання завтра


int* transformNumToArray(long number){
    int* arr = new int[1000];
    int i = 0;
    while (number != 0){
        arr[i+1] = number % 10;
        number = number / 10;
        i++;
    }
    arr[0] = i;

    return arr;
};

bool checkIfNumIsPalindrome(long number){
    int* arr = transformNumToArray(number);
    bool isPalindrome = true;


    int halfOfLength = arr[0] / 2;
    if(arr[0]%2 != 0){
        halfOfLength++;
    }
    for(int i = 0; i < halfOfLength; i++){
        if(arr[i+1] != arr[arr[0]-i]){
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}


void task1(int n){
    cout << "Task 1\n";
    int arrayOfCoolPalindromes[n];
    int index = 0;
    for (int i = 1; i <=n; i++){
        if(!checkIfNumIsPalindrome(i)){
            continue;
        }
        int sqrOfNum = pow(i, 2);
        if(checkIfNumIsPalindrome(sqrOfNum)){
            arrayOfCoolPalindromes[index] = i;
            index++;
        }
    }
    for(int k=0; k<index; k++){
        cout << arrayOfCoolPalindromes[k] << '\n';
    }
}

void task3(char cstring[]){
    int countOfWords = 1;
    bool isPreviousSpace = false;

    for(int i = 0; cstring[i] != '\0'; i++){
        if(isspace(cstring[i]) and !isPreviousSpace){
            countOfWords++;
            isPreviousSpace = true;
            continue;
        }
        isPreviousSpace = false;
    }

    cout << "\nTask 3:\n" << "Count of words: " << countOfWords;

}


void task2(){

}

int main(){
    task1(100);


    char cstring[] = "It is simply the duty of the elite to protect the ignorant masses. -Asuka Langley";
    task3(cstring);

    return 0;
}